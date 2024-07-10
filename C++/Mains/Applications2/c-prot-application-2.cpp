#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "../../Headers/ReadAllBytes.h"
using namespace std;

int main(){
    char arr[8] = "MALWARE";
    string _directory;
    cout<<"Dosya Diznini Giriniz :\n ";
    cin>>_directory;
    char *arr2 = ReadAllBytes(_directory);
    streamoff fileSize = sizeof(arr2);

    for (int i = 0; i < fileSize; i++)
    {
        char temp[8]  = {arr2[i], arr2[i+1], arr2[i+2], arr2[i+3], arr2[i+4], arr2[i+5], arr2[i+6]};
        strncpy(temp, temp, 8);
        if(strcmp(temp, arr) == 0){
            cout<<"Malware bulundu\n";
            break;
        }
        else{
            cout<<"Malware bulunamadı\n";
            break;
        }
    }
    
}
