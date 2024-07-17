#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include <vector>
#include <fstream>
#include "../../Headers/Methods.h"
namespace fs = std::filesystem;
using namespace std;
 
int main() {
    string path, keyword;
    cout<<"Klasör yolunu giriniz (Enter the folder path) : ";
    cin>>path;
    cout<<"Aranacak ifadeyi giriniz (Enter the expression to search for) : ";
    cin>>keyword;
    cout<<"\n\n";
    vector<string> directories =  sub_dir_listFiles(path);

    for(const auto &entry : directories){
        string paths = entry;
        search(paths, keyword.c_str());
    }
    cout<<"\n---------------------------------\n\n";
}