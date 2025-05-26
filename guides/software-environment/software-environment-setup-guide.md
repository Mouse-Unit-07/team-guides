# Software Environment Setup Guide
All installations and setup needed for Micromouse software development.
Required as an alternative to a Docker container due to lack of a mainstream Linux toolchain for AVR32 MCU. 

## Installations
- Microchip Studio IDE
  - https://www.microchip.com/en-us/tools-resources/develop/microchip-studio
  - installing the IDE will install the AVR32 toolchain for CMake to use 
- Git Bash
  - https://git-scm.com/downloads/win
- MSYS2
  - https://www.msys2.org/
  - use default path `C:\msys64`
  - open MSYS2 MINGW64 Terminal and run the following commands:
```
pacman -Syu

[close and restart terminal]

pacman -Su

pacman -S mingw-w64-x86_64-gcc \
            mingw-w64-x86_64-gcc-libs \
            mingw-w64-x86_64-gcov \
            mingw-w64-x86_64-cmake \
            mingw-w64-x86_64-ninja
```

- Python and pip
  - https://www.python.org/downloads/
  - make sure to check "Add Python to PATH"
  - on Windows command prompt run `pip install gcovr`
  - if pip isn't discoverable, follow steps in below Environment Variables section first and then run the pip install again

## Environment Variables
- add below to system PATH variables for:
  - Python (if not done automatically):
    - `C:\Users\`[your_user_name]`\AppData\Local\Programs\Python\Python39`
  - pip:
    - `C:\Users\`[your_user_name]`\AppData\Local\Programs\Python\Python39\Scripts`
  - gcc, g++, gcov, cmake, ninja
    - `C:\msys64\mingw64\bin`
  

## Check installations
- run and verify below on MSYS2 MINGW64 terminal to see specified version number or higher:
  - `gcc --version` -> should return 15.0.1+
  - `g++ --version` -> should return 15.0.1+
  - `gcov --version` -> should return 15.0.1+
  - `cmake --version` -> should return 4.0.2+
  - `ninja --version` -> should return 1.12.1+

- run and verify below on Windows command prompt to see specified version number or higher:
  - `python --version` -> should return 3.9.10+
  - `pip --version` -> should return 25.1.1+
  - `gcovr --version` -> should return 8.3+

- verify that AVR32 toolchain is installed:
  - `C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin`