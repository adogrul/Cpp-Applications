#ifndef _FIND
#define _FIND

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <filesystem>
#include <vector>
#include "Methods.h"

using namespace std;
namespace fs = std::filesystem;


int get_file_size(string _directory){
/*(TR) İmlecin konumunu döndürüp dosya boyutunu bulunur.
(EN) Returns the position of the cursor and finds the file size.
*/
    ifstream file(_directory, ios::out | ios::binary);
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
    file.close();
    return arr;
}


void search(string path ,const char *arr){
/*(TR) Dosya içerisinde arama yapar ve eğer aranan ifade bulunursa konumunu ekrana yazdırır.
(EN) Searches the file and if the searched expression is found, prints its location to the screen.
*/
    char* arr2 = ReadAllBytes(path); /*(TR) Dosyayı okuyup bir diziye atar ve dizi adresini döndürür.
    (EN) Reads the file and assigns it to an array and returns the array address.
    */
    bool flag = false; //(TR) Kontrol değişkeni | (EN) Control variable
    int fileSize = get_file_size(path);
    int length = strlen(arr);
    //cout<<length<<endl;

    for (int i = 0; i < fileSize-length; i++)
    {
        char* temp = new char[length + 1]; //(TR) Statik bir dizi sabit bir ifade bekleyeceği için hata verir bu yüzden dinamik bir dizi oluşturuldu. 
        // (EN) A static array gives an error because it expects a constant expression, so a dynamic array is created.   
        strncpy(temp, arr2 + i, length); //(TR) arr2 + i ifadesi arama yapılacak dosyanın i. karakterinden başlayarak length kadar karakteri temp dizisine kopyalar.
        // (EN) The expression arr2 + i copies the characters of the file to be searched starting from the i. character to the temp array for length characters.
        temp[length] = '\0';   
        if(strcmp(arr, temp) == 0){
            cout<<"\n";
            cout<<path<<" >>>: "<<arr<<" ifadesi "<<i<<" : ("<<(void*)(arr2 + i)<<") adresinde bulundu\n";    
            flag = true;
            delete[] temp; // (TR) Bellek sızıntısını önlemek için temp dizisi silindi. 
            // (EN) The temp array is deleted to prevent memory leakage.     
            break;
        }
        delete[] temp;
    }
    if (!flag)
    {
        cout<<path<<" >>>: "<<arr<<" ifadesi herhangi bir konumda bulunamadı\n";
    }
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



vector<string> list_PE_Files(const string& path) {
    vector<string> directories;
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
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


#endif 