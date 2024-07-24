# C++ File Searcher with KMP Algorithm

This C++ utility searches for specific keywords within files located in a given directory using the Knuth-Morris-Pratt (KMP) string matching algorithm. The program also handles reading keywords from a CSV file.

## Features

- **Directory Listing**: Lists all files in a specified directory.
- **KMP Algorithm Implementation**: Searches for patterns (keywords) within files using the KMP algorithm.
- **CSV Keyword Loading**: Loads search keywords from a CSV file.

## Prerequisites

- C++ compiler that supports C++11 or later.
- The `KMP.hpp` header file should be available in the `../../Headers/` directory or something like that.

## Installation

1. **Clone the Repository**

    Clone the repository to your local machine:

    ```bash
    git clone <repository-url>
    cd <project-directory>
    ```

2. **Compile the Code**

    Use your preferred C++ compiler to compile the code. For example, using `g++`:

    ```bash
    g++ -o file_searcher main.cpp
    ```

    Ensure that the `KMP.hpp` file is correctly located in the `../../Headers/` directory relative to `main.cpp`.

## Usage

1. **Run the Program**

    Execute the compiled program:

    ```bash
    ./file_searcher
    ```

2. **Input Directory and CSV File Path**

    - **Directory Path**: Enter the path to the directory containing the files you want to search.
    - **CSV File Path**: Enter the path to the CSV file containing the keywords. Each line in the CSV file should be a separate keyword.

3. **Output**

    - The program will list the files in the specified directory.
    - It will search each file for the keywords listed in the CSV file.
    - It will display any matches found for each keyword.

## Example

