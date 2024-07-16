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
    cout<<"Aranacak ifadeyi giriniz (Enter the expression to search for) : ";
    cin>>keyword;
    cout<<"Dosya Dizinini Giriniz (Enter the file's directory) : ";
    cin>>_directory;
    search(_directory,keyword.c_str());
    cout<<"Arama işlemi tamamlandı (Search process completed)\n";
    return 0;
    
}
