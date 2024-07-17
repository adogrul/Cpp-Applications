# Recursive File Keyword Search Utility

## Overview
This C++ program recursively searches for a specified keyword within all files in a directory and its subdirectories.

## How it Works
1. **Main Function**
   - Prompts the user to enter the directory path (`path`) to search.
   - Prompts the user to enter the keyword (`keyword`) to search for within files.
   - Calls `sub_dir_listFiles` function from `"Methods.h"` to recursively list all regular files in the specified directory and its subdirectories.
   - Iterates through each file found and calls `search` function from `"Methods.h"` to search for `keyword` within each file.
   - Prints the location of the keyword in each file if found, otherwise indicates that the keyword was not found.

2. **Usage**
   - Compile the program with `"Methods.h"` included and ensure proper directory path and keyword input during execution.
   - Requires C++17 or later for `<filesystem>` support and standard library headers (`<iostream>`, `<fstream>`, `<vector>`, `<filesystem>`, `<stdlib.h>`, `<stdio.h>`) and `"Methods.h"`.

3. **Example**
   - Example usage prompts user to enter the directory path and keyword, recursively searches all files within the directory and its subdirectories, and displays the search results.

## Notes
- Ensure that the directory path entered by the user is valid and accessible.
- The program assumes that `"Methods.h"` contains the necessary functions `sub_dir_listFiles` for listing files recursively and `search` for performing keyword searches within files.
