#include "../../Headers/KMP.hpp"
#include <iostream>

int main()
{
	std::string path;
    std::cout<<"Klasör Yolu Giriniz: ";
    std:cin>>path;
    string csvFilePath;
    cout << "CSV dosyasının dizinini giriniz(Enter the path of the CSV file): ";
    cin >> csvFilePath;
    ifstream csvFile(csvFilePath);
    vector<string> keywords;
    if (csvFile.is_open()) {
        string line;
        while (getline(csvFile, line)) {
            keywords.push_back(line); // Her satırı anahtar kelime olarak vector'e ekle
        }
        csvFile.close();
    } else {
        cerr << "CSV dosyası açılamadı!(CSV file can not open)" << endl;
        return 1;
    }

    vector<string> paths = sub_dir_listFiles(path);
     for(auto &entry : paths){
        std::string filePath = entry;
        for (auto &keyword : keywords) {
            KMPSearch(keyword, filePath);
        break;
        }
    }
	return 0;
}