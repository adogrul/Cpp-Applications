#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include <vector>
#include <fstream>
#include "../../Headers/Methods.h"
namespace fs = std::filesystem;
using namespace std;

int main(){
    string folderPath,keywords;
    cout << "Enter the folder path: ";
    cin >> folderPath;
    cout << "Enter the keywords: ";
    cin >> keywords;
    vector <string> directories = sub_dir_listFiles(folderPath);
    for (auto &entry : directories){
        string filePath= entry;
        char* arr = ReadAllBytes(filePath);
        if (arr[0] == 'M' && arr[1] == 'Z')
        {
            search(filePath, keywords.c_str());
        }
         delete[] arr; // arr dizisi serbest bırakılıyor
    }
    
}   