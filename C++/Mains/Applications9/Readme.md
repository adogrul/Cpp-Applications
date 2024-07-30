# Rabin Karp Algorithm Implementation in C++

This repository contains a C++ implementation of the Rabin Karp algorithm, as described in the CLRS (Introduction to Algorithms) book. The program reads a list of keywords from a CSV file and searches for these keywords in all files within a specified directory using the Rabin Karp string matching algorithm.

## Features

- Reads keywords from a CSV file.
- Searches for keywords in all files within a specified directory.
- Utilizes the Rabin Karp algorithm for efficient string matching.
- Prints the indices where patterns (keywords) are found in the text files.

## Prerequisites

- C++ compiler (e.g., g++)
- Standard C++ libraries

## Usage

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/rabin-karp-cpp.git
    cd rabin-karp-cpp
    ```

2. Compile the program:
    ```sh
    g++ -o rabin_karp main.cpp
    ```

3. Run the program:
    ```sh
    ./rabin_karp
    ```

4. When prompted, enter the directory path containing the text files and the path to the CSV file containing the keywords:
    ```
    Enter the folder directory: /path/to/directory
    Enter the csv file path: /path/to/keywords.csv
    ```

## Code Explanation

The program consists of the following main components:

### search Function

This function implements the Rabin Karp algorithm:
```cpp
void search(string keywords, string filePath, int q);
```
**1. keywords**: The keyword to search for.

**2. filePath**: The path to the file in which to search.

**3.q**: A prime number used in the hashing function.

### Main Function
The main function handles user input and coordinates the search:

```cpp
int main();
```

- Prompts the user for the directory path and CSV file path.
- Reads keywords from the CSV file.
- Searches for each keyword in each file within the specified directory.

### Utility Functions
- get_file_size: Returns the size of a file.
- ReadAllBytes: Reads all bytes from a file.
- sub_dir_listFiles: Lists all files in a directory.

### Example
Given a directory /texts with files and a CSV file keywords.csv containing:

```
keyword1
keyword2
```
Running the program with **/texts** and **keywords.csv** will search for **keyword1** and keyword2 in all files within **/texts.**