# Aho-Corasick Multi-Pattern String Matching

This project implements the Aho-Corasick algorithm for multi-pattern string matching. The program reads keywords from a CSV file and searches for these keywords in all files within a specified directory. The results show the occurrences of each keyword in each file.

## Features

- Reads keywords from a CSV file.
- Searches for these keywords in all files in the specified directory.
- Uses the Aho-Corasick algorithm for efficient multi-pattern matching.
- Outputs the occurrences of each keyword in each file.

## Requirements

- C++ compiler (supporting C++11 or later)
- Standard C++ libraries

## Usage

1. Clone or download the repository.
2. Compile the `main.cpp` file using a C++ compiler.
3. Run the compiled executable and provide the paths to the CSV file and the directory containing the files to be searched.

### Compilation

```bash
g++ -o aho_corasick main.cpp

CSV dosyasının yolunu girin: keywords.csv
Klasörün yolunu girin: /path/to/directory
