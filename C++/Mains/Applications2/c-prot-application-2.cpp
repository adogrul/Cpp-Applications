#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "../../Headers/Methods.h"
using namespace std;

int main(){
    string _directory;
    string keyword;
    cout<<"Aranacak ifadeyi giriniz : ";
    cin>>keyword;
    cout<<"Dosya Dizinini Giriniz :\n ";
    cin>>_directory;


    char *arr2 = ReadAllBytes(_directory);
    int fileSize = get_file_size(_directory);
    search(arr2, fileSize, keyword.c_str());
}
