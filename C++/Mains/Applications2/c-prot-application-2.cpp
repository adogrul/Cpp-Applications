#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "../../Headers/Methods.h"
using namespace std;

int main(){
    char arr[8] = "MALWARE";

    string _directory;
    cout<<"Dosya Dizinini Giriniz :\n ";
    cin>>_directory;

    char *arr2 = ReadAllBytes(_directory);
    int fileSize = get_file_size(_directory);                            
    cout<<fileSize<<endl;                                          
    search(arr2, fileSize, arr);
}
