#ifndef _FIND
#define _FIND

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <filesystem>
#include <vector>
#include <algorithm> // Add this line to include the <algorithm> header
#include <windows.h>
//
using namespace std;
namespace fs = std::filesystem;


int get_file_size(string _directory){
/*(TR) İmlecin konumunu döndürüp dosya boyutunu bulunur.
(EN) Returns the position of the cursor and finds the file size.
*/
    ifstream file(_directory, ios::in | ios::binary);
    file.seekg(0, ios::end); 
    int fileSize = file.tellg();
    return fileSize;

}

char* ReadAllBytes(const string& _directory){
/*(TR) Dosyayı okuyup bir diziye atar ve dizi adresini döndürür.
(EN) Reads the file and assigns it to an array and returns the array address.
*/

    ifstream file(_directory, ios::out | ios::binary);
    int fileSize = get_file_size(_directory);
    if (fileSize < 0) {
        return nullptr;
    }

    char* arr = new char[fileSize + 1]();//(TR) Statik bir dizi sabit bir ifade bekleyeceği için hata verir bu yüzden dinamik bir dizi oluşturuldu. 
    // (EN) A static array gives an error because it expects a constant expression, so a dynamic array is created.
    file.read(arr, fileSize);
    arr[fileSize] = '\0';
    file.close();
    return arr;
}
bool SearchInSection(const BYTE* sectionStart, DWORD sectionSize, const std::string& searchText) {
    std::string sectionData(reinterpret_cast<const char*>(sectionStart), sectionSize);
    return sectionData.find(searchText) != std::string::npos;
}

void search(const std::string& path, const char* arr) {
    // Dosyayı okuyup bir diziye atar ve dizi adresini döndürür.
    BYTE* arr2 = reinterpret_cast<BYTE*>(ReadAllBytes(path));
    if (!arr2) {
        std::cerr << "Dosya okunamadı." << std::endl;
        return;
    }

    int fileSize = get_file_size(path);
    if (fileSize <= 0) {
        std::cerr << "Geçersiz dosya boyutu." << std::endl;
        delete[] arr2;
        return;
    }

    IMAGE_DOS_HEADER* dosHeader = reinterpret_cast<IMAGE_DOS_HEADER*>(arr2);
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        std::cerr << "Geçersiz DOS header." << std::endl;
        delete[] arr2;
        return;
    }

    IMAGE_NT_HEADERS* ntHeaders = reinterpret_cast<IMAGE_NT_HEADERS*>(arr2 + dosHeader->e_lfanew);
    if (ntHeaders->Signature != IMAGE_NT_SIGNATURE) {
        std::cerr << "Geçersiz NT header." << std::endl;
        delete[] arr2;
        return;
    }

    IMAGE_SECTION_HEADER* sectionHeaders = IMAGE_FIRST_SECTION(ntHeaders);

    bool found = false;
    for (int i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i) {
        IMAGE_SECTION_HEADER& section = sectionHeaders[i];
        BYTE* sectionStart = arr2 + section.PointerToRawData;
        DWORD sectionSize = section.SizeOfRawData;

        if (sectionStart + sectionSize > arr2 + fileSize) {
            std::cerr << "Bölüm dosya boyutunu aşıyor." << std::endl;
            continue;
        }

        if (SearchInSection(sectionStart, sectionSize, arr)) {
            std::cout << path << ":> BULUNDU (" << section.PointerToRawData << " adresinde ve \"" << section.Name << "\" section'ı içerisinde)" << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << path << ": BULUNAMADI " << std::endl;
    }

    delete[] arr2;
}

vector<string> sub_dir_listFiles(const string& path) {/*(TR) Klasördeki dosyaları listeler.
(EN) Lists the files in the folder.
*/

    vector<string> directories;
    try {
        for (const auto& entry : fs::recursive_directory_iterator(path)) {
            if (fs::is_regular_file(entry)) {
                cout << entry.path() << endl;
                directories.push_back(entry.path().string());
            }
        }
    } catch (const filesystem::filesystem_error& ex) {
        cerr << "Hata oluştu: " << ex.what() << endl;
    }
    cout << "Toplam " << directories.size() << " dosya bulundu\nOkuma Başarılı\n\n---------------------------------\n\n";
    return directories;
}

bool isExecutableSection(const IMAGE_SECTION_HEADER& section) {
    return section.Characteristics & IMAGE_SCN_MEM_EXECUTE;
}

void searchInPEFile(const std::string& filePath, const std::string& searchString) {
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << filePath << ": Dosya açma hatası" << std::endl;
        return;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) {
        std::cerr << filePath << ": Dosya okuma hatası" << std::endl;
        return;
    }

    PIMAGE_DOS_HEADER dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(buffer.data());
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        std::cerr << filePath << ": Geçerli PE dosyası değil" << std::endl;
        return;
    }

    PIMAGE_NT_HEADERS ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(buffer.data() + dosHeader->e_lfanew);
    if (ntHeaders->Signature != IMAGE_NT_SIGNATURE ||
        (ntHeaders->FileHeader.Machine != IMAGE_FILE_MACHINE_I386 && ntHeaders->FileHeader.Machine != IMAGE_FILE_MACHINE_AMD64)) {
        std::cerr << filePath << ": Geçerli PE dosyası değil" << std::endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i) {
        PIMAGE_SECTION_HEADER section = reinterpret_cast<PIMAGE_SECTION_HEADER>(
            reinterpret_cast<char*>(ntHeaders) + sizeof(IMAGE_NT_HEADERS) + (i * sizeof(IMAGE_SECTION_HEADER))
        );
        if (isExecutableSection(*section)) {
            char* sectionStart = buffer.data() + section->PointerToRawData;
            char* sectionEnd = sectionStart + section->SizeOfRawData;
            char* pos = std::search(sectionStart, sectionEnd, searchString.begin(), searchString.end());
            if (pos != sectionEnd) {
                std::cout << filePath << ": BULUNDU (" << std::distance(buffer.data(), pos) << " adresinde ve \"" 
                          << std::string(reinterpret_cast<char*>(section->Name), 8) << "\" section'ı içerisinde)" << std::endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << filePath << ": BULUNAMADI" << std::endl;
    }
}




#endif 