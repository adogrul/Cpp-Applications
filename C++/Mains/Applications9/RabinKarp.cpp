/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <limits.h>
#include "../../Headers/Methods.hpp"
using namespace std;

#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
void search(string keywords, string filePath, int q)
{
    char* pat = (char*)keywords.c_str();
	int M = strlen(keywords.c_str());
	int N = get_file_size(filePath);
    char *txt = ReadAllBytes(filePath);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) {

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j]) {
					break;
				}
			}

			// if p == t and pat[0...M-1] = txt[i, i+1,
			// ...i+M-1]

			if (j == M)
				cout << "Pattern found at index " << i
					<< endl;
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			// We might get negative value of t, converting
			// it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

/* Driver code */
int main()
{
    int q = 7; // A prime number
    string dir_Path;
    cout<<"klasör dizinini giriniz(Enter the folder directory): ";
    cin>>dir_Path;
    string csv_Path;
    cout<<"csv dosyasının yolunu giriniz(Enter the csv file path): ";
    cin>>csv_Path;

    vector<string> dir_arr = sub_dir_listFiles(dir_Path);
    vector<string> keywords;
    ifstream csvFile(csv_Path);

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

    for (const auto &entry : dir_arr) {
        for (const auto &keyword : keywords) {
            search(keyword ,entry,q);
        }
    }

    return 0;
}

// pat : keywords of CSV file
// txt : file content