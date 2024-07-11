#include <iostream>
#include <fstream>
#include <string>
#include "../../Headers/Methods.h"


using namespace std;

int main(){
    std::cout<<"\n\nİlk 2 baytını görmek istediğin dosyanın dizinini gir: ";
    string _directory;
    cin>>_directory;

    char *arr = ReadAllBytes(_directory);//(TR)Kullanıcı tanımlı dizinin tüm baytlarını okuyan ve dödürülen diziyi tutan dizimize atama yapan blok
    //(EN) Block that reads all bytes of user defined directory and assigns it to our array that holds the returned array 

    ofstream file2 ("first2bytes.txt", ios::out | ios::binary); //(TR) Terminal ekranında derleyiciye bazen baytlar ile beraber değişik karakterler verebilir bu yüzden binary modda açıldı.
    //(EN) Sometimes the compiler can give different characters to the compiler with bytes on the terminal screen, so it was opened in binary mode.
    for(int i =0; i<2; i++){
        file2<<arr[i];
    }

    return 0;
}
