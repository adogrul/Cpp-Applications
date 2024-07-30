
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <limits.h>
#include "../../Headers/RabinKarp.hpp"
using namespace std;

int main()
{
    int q = 7; // A prime number
    string dir_Path;
    cout<<"klasör dizinini giriniz(Enter the folder directory): ";
    cin>>dir_Path;
    string csv_Path;
    cout<<"csv dosyasının yolunu giriniz(Enter the csv file path): ";
    cin>>csv_Path;

    vector<string> dir_arr = sub_dir_listFiles(dir_Path);
    vector<string> keywords;
    ifstream csvFile(csv_Path);

    if (csvFile.is_open()) {
        string line;
        while (getline(csvFile, line)) {
            keywords.push_back(line);
        }
        csvFile.close();
    } else {
        cerr << "CSV dosyası açılamadı!" << endl;
        return 1;
    }

    for (const auto &entry : dir_arr) {
        for (const auto &keyword : keywords) {
            search(keyword ,entry,q);
        }
    }

    return 0;
}
