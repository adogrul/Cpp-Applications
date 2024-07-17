# File Search Utility with Dynamic Memory Allocation

## Overview
This C++ header file (`Methods.h`) provides utility functions for file handling and searching within a directory and its subdirectories. It includes functions for reading file contents into memory, searching for a specified keyword within files, and listing all regular files in a directory recursively.

## Functions

1. **get_file_size**
   - **Description:** Retrieves the size of a file given its path.
   - **Parameters:** `_directory` - Path to the file.
   - **Returns:** Size of the file in bytes (`int`).

2. **ReadAllBytes**
   - **Description:** Reads the entire content of a file into a dynamically allocated character array.
   - **Parameters:** `_directory` - Path to the file.
   - **Returns:** Dynamically allocated character array (`char*`) containing file content.

3. **search**
   - **Description:** Searches for a specified text expression (`arr`) within a file (`path`) and prints its location if found.
   - **Parameters:** `path` - Path to the file, `arr` - Text expression to search.
   - **Returns:** Void.

4. **sub_dir_listFiles**
   - **Description:** Lists all regular files in a directory and its subdirectories.
   - **Parameters:** `path` - Path to the directory.
   - **Returns:** `vector<string>` containing paths to all regular files.

## Usage

To use these functions:
- Include `"Methods.h"` in your C++ source file.
- Ensure your C++ compiler supports C++17 or later for `<filesystem>` support.
- Compile your program with `"Methods.h"` included and link it properly.

## Example

```cpp
#include <iostream>
#include "Methods.h"

int main() {
    std::string folderPath, keywords;
    std::cout << "Enter the folder path: ";
    std::cin >> folderPath;
    std::cout << "Enter the keywords to search: ";
    std::cin >> keywords;

    std::vector<std::string> directories = sub_dir_listFiles(folderPath);
    for (const auto &entry : directories) {
        std::string filePath = entry;
        char* arr = ReadAllBytes(filePath);
        if (arr) {
            if (arr[0] == 'M' && arr[1] == 'Z') {
                search(filePath, keywords.c_str());
            }
            delete[] arr; // Free the dynamically allocated array
        }
    }

    return 0;
}
