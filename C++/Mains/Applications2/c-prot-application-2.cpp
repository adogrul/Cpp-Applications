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
    
    ifstream file(_directory, ios::out | ios::binary);
    file.seekg(0, ios::end); 
	int fileSize = file.tellg();                  //Aynı kodu header'da kullandık dosya boyutunu veriyor
    file.seekg(0, ios::beg);                            //(EN) Get the size of the array
                                
    cout<<fileSize<<endl;                                          
    for (int i = 0; i < fileSize; i++)
    {
        char temp[8]  = {arr2[i], arr2[i+1], arr2[i+2], arr2[i+3], arr2[i+4], arr2[i+5], arr2[i+6]};    //(TR) Dizinin her 8 elemanını al     
                                                                                                        //(EN) Get the every 8 value of array
        strncpy(temp, temp, 8);
        if(strcmp(temp, arr) == 0){
            cout<<"\"MALWARE\" ifadesi "<<i<<" : ("<<(void*)(arr2 + i)<<") adresinde bulundu\n";    //(TR)cout işaretçileri void olarak yazdırabildiği için bu şşekilde adresini de yazdık offset değerini de
                                                                                     //(EN) We wrote the address of the "MALWARE" expression in this way because cout can print pointers as void
            break;
        }
                                
    }
    
}