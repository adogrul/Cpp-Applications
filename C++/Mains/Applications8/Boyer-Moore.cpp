#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "../../Headers/BoyerMoore.hpp"
using namespace std;


/* Driver code */
int main() {
    string directory;
    cout << "Klasör yolunu gir: ";
    cin >> directory;
    string csvPath;
    cout << "CSV dosyasının yolunu gir: ";
    cin >> csvPath;
    vector<string> dir_arr = sub_dir_listFiles(directory);
    vector<string> keywords;
    ifstream csvFile(csvPath);
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
            search(entry, keyword);
        }
    }

    return 0;
}
