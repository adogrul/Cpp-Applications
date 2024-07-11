#ifndef _FIND
#define _FIND

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int get_file_size(string _directory){
    ifstream file(_directory, ios::out | ios::binary);
    file.seekg(0, ios::end); 
    int fileSize = file.tellg();
    return fileSize;
}

char* ReadAllBytes(string _directory){
    ifstream file(_directory, ios::out | ios::binary);  //(TR)_directory değişkenine girilecek dosyayı açan kod parçası
                                                        //(EN)code snippet that opens the file to be entered in the _directory variable
    int fileSize = get_file_size(_directory);
    if (fileSize < 0) {
        return nullptr;
    }

    char* arr = new char[fileSize + 1]();     // (TR) Daha iyi işlem yapmak ve bellekten kazanmak için dosya boyutu kadar bellekte yer ayırdım
                                                            // calloc() kullanmamdaki amaç bellekte sıralı bir şekilde yer ayırmak verileri çekerken sıralı bir düzende çekmek
                                                            // (EN) I allocated memory in the amount of the file size to operate better and save memory
                                                            // The reason I used calloc() is to allocate memory in a sequential order in memory and to fetch the data in a sequential order.
    file.read(arr, fileSize);                               
    file.close();
    return arr;
}



void search(const char *arr2, int fileSize, const char *arr){
    bool flag = false;
    int length = strlen(arr);
    cout<<length<<endl;

    for (int i = 0; i < fileSize-length; i++)
    {
        char* temp = new char[length + 1]; 
        
        strncpy(temp, arr2 + i, length); 
        temp[length] = '\0';
        
        //strncpy(temp, temp, length);
        if(strcmp(arr, temp) == 0){
            cout<<arr<<" ifadesi "<<i<<" : ("<<(void*)(arr2 + i)<<") adresinde bulundu\n";    
            flag = true;
            delete[] temp;
            break;
        }

        delete[] temp;

    }

    if (!flag)
    {
        cout<<arr<<" ifadesi herhangi bir konumda bulunamadı\n";
    }

}

#endif 