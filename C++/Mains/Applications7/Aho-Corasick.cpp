#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include "../../Headers/Methods.hpp"
using namespace std;

// Maksimum durum sayısı
const long int MAXS = 100000; 
  
// Girdi alfabesindeki maksimum karakter sayısı
const int MAXC = 128;  // ASCII karakter seti için 128
  
// ÇIKIŞ FONKSİYONU out[] ile IMPLEMENT EDİLİR
int out[MAXS]; 
  
// HATA FONKSİYONU f[] ile IMPLEMENT EDİLİR
int f[MAXS]; 
  
// GOTO FONKSİYONU (VEYA TRIE) g[][] ile IMPLEMENT EDİLİR
int g[MAXS][MAXC]; 

// Karakterlerin indekslerini belirten eşleme tablosu
unordered_map<char, int> charToIndex;

// Dize eşleştirme makinesini inşa eder.
int buildMatchingMachine(vector<string> &arr, int k) { 
    memset(out, 0, sizeof(out)); 
    memset(g, -1, sizeof(g)); 

    // Karakter indeksleme tablosunu doldurun
    for (int i = 0; i < MAXC; ++i) charToIndex[(char)i] = i;

    int states = 1; 
  
    for (int i = 0; i < k; ++i) { 
        const string &word = arr[i]; 
        int currentState = 0; 
  
        for (char c : word) { 
            int ch = charToIndex[c]; 

            if (currentState >= MAXS || ch >= MAXC) {
                cerr << "Geçersiz durum veya karakter: currentState=" << currentState << ", ch=" << ch << endl;
                continue;
            }

            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++; 
  
            currentState = g[currentState][ch]; 
        } 
  
        out[currentState] |= (1 << i); 
    } 
  
    for (int ch = 0; ch < MAXC; ++ch) 
        if (g[0][ch] == -1) 
            g[0][ch] = 0; 
  
    memset(f, -1, sizeof(f)); 
    queue<int> q; 
  
    for (int ch = 0; ch < MAXC; ++ch) { 
        if (g[0][ch] != 0) { 
            f[g[0][ch]] = 0; 
            q.push(g[0][ch]); 
        } 
    } 
  
    while (!q.empty()) { 
        int state = q.front(); 
        q.pop(); 
  
        for (int ch = 0; ch < MAXC; ++ch) { 
            if (g[state][ch] != -1) { 
                int failure = f[state]; 
                while (g[failure][ch] == -1) 
                      failure = f[failure]; 
  
                failure = g[failure][ch]; 
                f[g[state][ch]] = failure; 
                out[g[state][ch]] |= out[failure]; 
                q.push(g[state][ch]); 
            } 
        } 
    } 
  
    return states; 
} 
  
int findNextState(int currentState, char nextInput) { 
    int ch = charToIndex[nextInput];
    if (currentState >= MAXS || ch >= MAXC) {
        cerr << "Geçersiz durum veya karakter: currentState=" << currentState << ", ch=" << ch << endl;
        return 0; // Geçersiz durum için varsayılan duruma dön
    }
    while (g[currentState][ch] == -1) 
        currentState = f[currentState]; 
  
    return g[currentState][ch]; 
} 
  
void searchWords(vector<string> &arr, int k, const string &filePath) { 
    int size = get_file_size(filePath);
    char* text = ReadAllBytes(filePath);
    buildMatchingMachine(arr, k); 
    int currentState = 0; 
  
    for (int i = 0; i < size; ++i) { 
        currentState = findNextState(currentState, text[i]); 
  
        if (out[currentState] == 0)
            continue; 
  
        for (int j = 0; j < k; ++j) { 
            if (out[currentState] & (1 << j)) { 
                cout << "Kelime " << arr[j] << " " 
                     << i - arr[j].size() + 1 << " ile " << i << " arasında geçiyor" << endl; 
            } 
        } 
    } 
    delete[] text; // Ayrılan belleği serbest bırakmayı unutmayın
} 
  
int main() { 
    string csvPath;
    cout << "CSV dosyasının yolunu girin: ";
    cin >> csvPath;

    string dirPath;
    cout << "Klasörün yolunu girin: ";
    cin >> dirPath;

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

    vector<string> directories = sub_dir_listFiles(dirPath);
    int k = keywords.size();

    for (const auto &entry : directories) {
        string filePath = entry;
        searchWords(keywords, k, filePath);
    }
  
    return 0; 
}
