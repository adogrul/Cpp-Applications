# File Keyword Search Utility

## Overview
This C++ program searches for a specified keyword within a file specified by the user.

## How it Works
1. **Main Function**
   - Prompts the user to enter the keyword to search for (`keyword`).
   - Prompts the user to enter the directory path of the file to search (`_directory`).
   - Calls `search` function from `"Methods.h"` to search for `keyword` within `_directory`.
   - Prints the location of the keyword in the file if found, otherwise indicates that the keyword was not found.

2. **Usage**
   - Compile the program with `"Methods.h"` included and ensure proper file path input during execution.
   - Requires C++ compiler with support for standard library headers (`<iostream>`, `<fstream>`, `<string.h>`, `<stdlib.h>`, `<stdio.h>`) and `"Methods.h"`.

3. **Example**
   - Example usage prompts user to enter the keyword and file directory, performs the search, and displays the result.

## Notes
- Ensure that the file path entered by the user is valid and the file exists.
- The program assumes that `"Methods.h"` contains the necessary function `search` for performing keyword searches within files.
