#include <iostream>
#include <fstream>
#include <string>
#include "../../Headers/Methods.h"


using namespace std;

int main(){
    std::cout<<"\n\nİlk 2 baytını görmek istediğin dosyanın dizinini gir: ";
    string _directory;
    cin>>_directory;

	ReadAllBytes(_directory); //(TR)Kullanıcı tanımlı dizini okuyan blok
                              //(EN)Block that reads user defined directory  

    char *arr = ReadAllBytes(_directory); //(TR) Dödürülen diziyi tutan dizimiza atama yaptık
                                          //(EN) We assigned the returned array to our array that holds the array

    ofstream file2 ("first2bytes.txt", ios::out | ios::binary);
    
    for(int i =0; i<2; i++){
        file2<<arr[i];
    }

    return 0;
}
