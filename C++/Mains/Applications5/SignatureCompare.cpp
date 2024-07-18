#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <windows.h>
#include "../../Headers/Methods.hpp"

using namespace std;

int main(){
    string folderPath;
    cout << "Klasör Dizinini giriniz(Enter the folder path): ";
    cin >> folderPath;

    // CSV dosyasından anahtar kelimeleri oku ve bir vector'e ata
    string csvFilePath;
    cout << "CSV dosyasının dizinini giriniz(Enter the path of the CSV file): ";
    cin >> csvFilePath;
     // CSV dosyasının yolunu belirtin
    ifstream csvFile(csvFilePath);
    vector<string> keywords;
    if (csvFile.is_open()) {
        string line;
        while (getline(csvFile, line)) {
            keywords.push_back(line); // Her satırı anahtar kelime olarak vector'e ekle
        }
        csvFile.close();
    } else {
        cerr << "CSV dosyası açılamadı!" << endl;
        return 1;
    }

    // Dizindeki dosyaları listele
    vector<string> directories = sub_dir_listFiles(folderPath);

    // Her dosya için her anahtar kelimeyi searchInPEFile fonksiyonuna gönder
    for (auto &entry : directories) {
        string filePath = entry;
        for (auto &keyword : keywords) {
            searchInPEFile(filePath, keyword);
            break;
        }
    }
    return 0;
}
