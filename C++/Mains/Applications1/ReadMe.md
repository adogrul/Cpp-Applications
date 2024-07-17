# Reading First Two Bytes of a File

## Overview
This C++ program reads the first two bytes of a file specified by the user and writes them to a new file `first2bytes.txt`.

## How it Works
1. **Main Function**
   - Prompts the user to enter the directory of the file.
   - Calls `ReadAllBytes` function from `"Methods.h"` to read all bytes of the file into a character array (`char* arr`).
   - Opens `"first2bytes.txt"` file in binary mode (`ios::binary`) to ensure proper handling of byte data.
   - Writes the first two bytes from `arr` into `"first2bytes.txt"`.

2. **Usage**
   - Compile the program with `"Methods.h"` included and ensure proper file path input during execution.
   - Requires C++ compiler with support for standard library headers (`<iostream>`, `<fstream>`, `<string>`) and `"Methods.h"`.

3. **Example**
   - Example usage prompts user to enter the file directory, reads its first two bytes, and saves them to `"first2bytes.txt"`.

## Notes
- Ensure that the file path entered by the user is valid and the file exists.
- The program assumes that `"Methods.h"` contains the necessary function `ReadAllBytes` for reading file contents into memory.
