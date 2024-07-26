# Boyer-Moore String Matching Algorithm in C++
**Overview**

This project implements the Boyer-Moore string matching algorithm in C++ to efficiently search for patterns within files. It processes a directory of files and searches for multiple keywords specified in a CSV file.

**Features**

Implements the Boyer-Moore algorithm with the bad character heuristic.
Reads all files from a specified directory.
Searches for multiple keywords specified in a CSV file.
Outputs the position of the found patterns within each file.

## Getting Started
**Prerequisites**

A C++ compiler that supports C++11 or later.

CMake for building the project.

**Directory Structure**

```
your_project/
├── src/
│   ├── main.cpp
│   └── BoyerMoore.cpp
├── Headers/
│   ├── BoyerMoore.hpp
│   └── Methods.hpp
├── data/
│   ├── files/ (Place your files here)
│   └── keywords.csv (Place your keyword list here)
└── README.md
```
### Building the Project
**Clone the repository :**
```
git clone https://github.com/adogrul/StepbyStep_Malware_Detect/tree/main/C%2B%2B/Mains/Applications8
cd your_project

```



## Running the Program

**Prepare your data:**

*Place the files to be searched in the data/files directory.
Create a CSV file named keywords.csv in the data directory, with each line containing a keyword to search.*

**Run the executable:**
```
./Boyer-Moore.exe
```


**Follow the prompts to enter the directory and CSV file paths:**
````
Enter the directory path: data/files
Enter the CSV file path: data/keywords.csv
````

## Contributing
Contributions are welcome! Please create a pull request with a clear description of your changes.

License
This project is licensed under the MIT License. See the LICENSE file for more details.   

Acknowledgements
This project uses the Boyer-Moore string matching algorithm with the bad character heuristic.   

Contact
If you have any questions or suggestions, feel free to contact the project maintainer at ***dogrularda39@gmail.com***
