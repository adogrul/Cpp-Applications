# File Keyword Search in Binary Files Utility

## Overview
This C++ program searches for a specified keyword within binary files (identified by the presence of 'MZ' at the beginning of the file) within a specified directory and its subdirectories.

## How it Works
1. **Main Function**
   - Prompts the user to enter the directory path (`folderPath`) to search.
   - Prompts the user to enter the keyword (`keywords`) to search for within files.
   - Calls `sub_dir_listFiles` function from `"Methods.h"` to recursively list all regular files in the specified directory and its subdirectories.
   - Iterates through each file found and calls `ReadAllBytes` function from `"Methods.h"` to read the first two bytes of the file.
   - Checks if the first two bytes of the file are 'MZ' (indicating a binary executable file).
   - If the file is identified as a binary file, calls `search` function from `"Methods.h"` to search for `keywords` within the file.
   - Deletes the dynamically allocated character array (`arr`) after use to prevent memory leaks.

2. **Usage**
   - Compile the program with `"Methods.h"` included and ensure proper directory path and keyword input during execution.
   - Requires C++17 or later for `<filesystem>` support and standard library headers (`<iostream>`, `<fstream>`, `<vector>`, `<filesystem>`, `<stdlib.h>`, `<stdio.h>`) and `"Methods.h"`.

3. **Example**
   - Example usage prompts user to enter the directory path and keyword, recursively searches all binary files (starting with 'MZ') within the directory and its subdirectories, and displays the search results.

## Notes
- Ensure that the directory path entered by the user is valid and accessible.
- The program assumes that `"Methods.h"` contains the necessary functions `sub_dir_listFiles` for listing files recursively, `ReadAllBytes` for reading file contents into memory, and `search` for performing keyword searches within files.
