#include "../../Headers/KMP.hpp"
#include <iostream>

int main()
{
    string directory;
    cout << "Klasör yolunu gir: ";
    cin >> directory;
    string csvPath;
    cout << "CSV dosyasının yolunu gir: ";
    cin >> csvPath;
    vector<string> dir_arr = sub_dir_listFiles(directory);
    vector<string> keywords;
    ifstream csvFile(csvPath);
    if (csvFile.is_open()) {
        string line;
        while (getline(csvFile, line)) {
            keywords.push_back(line);
        }
        csvFile.close();
    } else {
        cerr << "CSV dosyası açılamadı!" << endl;
        return 1;
    }

    char* arr2 = ReadAllBytes(csvPath);
    for (auto &entry : dir_arr)
	{
        char* arr = ReadAllBytes(entry);	
        if(arr[0]='M'&&arr[1]=='Z')
		{
			std::string ntSignature = getNTHeaderSignature(entry);
			if (!ntSignature.empty()) 
			{
				std::cout << std::endl;
				std::cout <<entry<< "\nNT header signature found (ASCII):"<<ntSignature<<endl;
				KMPSearch(ntSignature,arr,entry);
				std::cout <<"\n\n";
        	}
        }
    }
	return 0;
}