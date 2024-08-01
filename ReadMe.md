# File Handling and Searching Project

This project consists of 5 different stages and one Header file: 
### [Application-1](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications1) , [Application-2](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications2) ,  [Application-3](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications3) , [Application-4](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications4) , [Application-5](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications5) , [Application-6](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications6) , [Application-7](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications7) , [Application-8](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications8) , [Application-9](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Mains/Applications9) , [Header File](https://github.com/adogrul/Cpp-Applications/tree/main/C%2B%2B/Headers)

## Application-1

When the program is executed, the first 2 bytes of a file, whose full path will be provided in the code, should be read and printed on the screen. This way, information about the file type can be obtained.

**Expected Output:**
```
C:\> uygulama1.exe
Dosyanın ilk iki baytı: MZ
```
## Application-2

When the program is executed, a file whose full path will be provided in the code should be read and the expression "MALWARE" should be searched within it. The offset value of the found position should be printed on the screen.

**Expected Output:**
```
Aranacak ifadeyi giriniz (Enter the expression to search for) : MALWARE
Dosya Dizinini Giriniz (Enter the file's directory) : C:\> uygulama2.exe
"MALWARE" ifadesi(expression) 4096 adresinde bulundu(found)
```

## Application-3

When the program is executed, the search operation in Application 2 should be applied to all files within a folder provided as an argument to the program. The search results should be informed to the user.

**Expected Output:**
```
Same as Application-2 but with more file outputs
```

## Applications-4

Application-4:
When the program is executed, the search operation in Application 2 should be applied to all files (excluding subfolders) within a folder provided as an argument to the program. However, the search should only be conducted in files in Portable Executable (PE) format. Other files should be skipped and the user should be informed. To determine whether a file is in PE format, it is sufficient to check if the first 2 bytes are "MZ". Detailed validation procedures are not required for this example. Once a file is determined to be in PE format, the search for the "MALWARE" expression should be conducted only within sections that have the "executable" flag. The location along with the section name should be informed to the user if found.

## Application-5
This project is a C++ program that searches for specific keywords in PE (Portable Executable) files within a specified folder. The keywords are read from a CSV file and the search results are printed to the console.

```
Klasör Dizinini giriniz(Enter the folder path): C:\example\path
CSV dosyasının dizinini giriniz(Enter the path of the CSV file): C:\example\path
C:\example\file is not PE File
```
## Application-6
This C++ utility searches for specific keywords within files located in a given directory using the Knuth-Morris-Pratt (KMP) string matching algorithm. The program also handles reading keywords from a CSV file.
he program will search for each keyword in each file within the specified directory and output the results.

**Input Directory and CSV File Path**

    - **Directory Path**: Enter the path to the directory containing the files you want to search.
    - **CSV File Path**: Enter the path to the CSV file containing the keywords. Each line in the CSV file should be a separate keyword.
    
**Output**

    - The program will list the files in the specified directory.
    - It will search each file for the keywords listed in the CSV file.
    - It will display any matches found for each keyword.

## Application-7
This project implements the Aho-Corasick algorithm for multi-pattern string matching. The program reads keywords from a CSV file and searches for these keywords in all files within a specified directory. The results show the occurrences of each keyword in each file.


## Header File

This C++ utility provides functions to search for a specific text expression within files in a directory and its subdirectories. It includes functions for reading files into memory and handling file size calculations.

#### Functions
**get_file_size()**
```
int get_file_size(string _directory){
/*
   (TR) İmlecin konumunu döndürüp dosya boyutunu bulunur.
   (EN) Returns the position of the cursor and finds the file size.
*/
}
```
**ReadAllBytes()**
```
char* ReadAllBytes(const string& _directory){
/*
   (TR) Dosyayı okuyup bir diziye atar ve dizi adresini döndürür.
   (EN) Reads the file and assigns it to an array and returns the array address.
*/
}

```
**search()**
```
void search(string path ,const char *arr){
/*
   (TR) Dosya içerisinde arama yapar ve eğer aranan ifade bulunursa konumunu ekrana yazdırır.
   (EN) Searches the file and if the searched expression is found, prints its location to the screen.
*/
}
```
**sub_dir_listFiles()**
```
vector<string> sub_dir_listFiles(const string& path) {
/*
   (TR) Klasördeki tüm dosyaları listeler.
   (EN) Lists the all files in the folder.
*/
}
```




[MIT](https://choosealicense.com/licenses/mit/)
