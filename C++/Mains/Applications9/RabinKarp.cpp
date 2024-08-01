/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <limits.h>
#include "../../Headers/RabinKarp.hpp"
using namespace std;



int main() 
{
    std::string dir_Path,csv_Path;
    cout<<"klasör dizinini giriniz(Enter the folder directory): ";
    cin>>dir_Path;
    cout<<"csv dosyasının dizinini giriniz(Enter the directory of the csv file): ";
    cin>>csv_Path;
    vector<std::string> file_Paths = sub_dir_listFiles(dir_Path);
    ifstream csvFile(csv_Path);
    vector<string> csv_Data;   
    if(csvFile.is_open())
	{
        string line;
        while (getline(csvFile, line))
		{
            csv_Data.push_back(line);
        }
        csvFile.close();
    } 
	else 
	{
        cerr << "CSV dosyası açılamadı!" << endl;
        return 1;
    }
	char* arr2 = ReadAllBytes(csv_Path);
    for (auto &entry : file_Paths)
	{
        char* arr = ReadAllBytes(entry);	
        if(arr[0]='M'&&arr[1]=='Z')
		{
			std::string ntSignature = getNTHeaderSignature(entry);
			if (!ntSignature.empty()) 
			{
				std::cout << std::endl;
				RKsearch(ntSignature,arr2,7);
				std::cout <<entry<< "\nNT header signature found (ASCII):"<<ntSignature;
				std::cout <<"\n\n";
        	}
        }
    }
    return 0;
}


// pat : keywords of CSV file
// txt : file content

//