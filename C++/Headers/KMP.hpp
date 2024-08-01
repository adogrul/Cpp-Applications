#include <iostream>
#include <cstring>
#include <filesystem>
#include "Methods.hpp"
void computeLPSArray(const std::string& arr, int M, int* lps);

void KMPSearch( std::string& pattern, char* text,std::string path)
{
	char* arr2 = (ReadAllBytes(path));
    // PathArr dizisinin bellekte yeterli yer kaplaması için ReadAllBytes fonksiyonunun doğru çalıştığından emin olun
    if (arr2 == nullptr) {
        std::cerr << "Failed to read file" << std::endl;
        return;
    }
    int M = strlen(text); // M, anahtar kelimenin boyutu
    int N = get_file_size(path); // Dosya boyutunu doğru hesaplayın
    if (M <= 0 || N <= 0) {
        std::cerr << "Invalid size for pattern or text" << std::endl;
        delete[] arr2; // Belleği temizleyin
        return;
    }

    // create lps[] that will hold the longest prefix suffix values for pattern
    int* lps = new int[M];
    
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pattern, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pattern[j] == arr2[i]) {
            j++;
            i++;
        }

        if (j == M) {
            std::cout << "İfade  (found pattern at )" << i - j <<" içinde bulundu"<< std::endl;
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != arr2[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    delete[] lps;
    delete[] arr2; // Belleği temizleyin
}

void computeLPSArray(const std::string& arr, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (arr[i] == arr[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
