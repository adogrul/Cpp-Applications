#ifndef _FIND
#define _FIND

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char* ReadAllBytes(string _directory){


    ifstream file(_directory, ios::out | ios::binary);  //(TR)_directory değişkenine girilecek dosyayı açan kod parçası
                                                        //(EN)code snippet that opens the file to be entered in the _directory variable
    
    file.seekg(0, ios::end); 
	streampos fileSize = file.tellg();                  //(TR)Kısaca imleci sona götürüp tellg ile konumunu dönüp boyutunu aldığımız
    file.seekg(0, ios::beg);                            //tekrar işlem yapmak için imleci başa getirdiğimiz kod parçası
                                                        //(EN)Here's the code snippet where we move the cursor to the end, retrieve its position
                                                        //with tell, and then reset it to the beginning for further operations.

    
    char* arr = (char*)calloc(fileSize, sizeof(char) + 1);  // (TR) Daha iyi işlem yapmak ve bellekten kazanmak için dosya boyutu kadar bellekte yer ayırdım
                                                            // calloc() kullanmamdaki amaç bellekte sıralı bir şekilde yer ayırmak verileri çekerken sıralı bir düzende çekmek
                                                            // (EN) I allocated memory in the amount of the file size to operate better and save memory
                                                            // The reason I used calloc() is to allocate memory in a sequential order in memory and to fetch the data in a sequential order.
    file.read(arr, fileSize);                               
    file.close();
    return arr;
}

#endif 