# Installation Instructions

This document provides instructions for setting up the development environment for 'Break this Game'. Follow the steps below to ensure all necessary dependencies are installed and the project can be built successfully.

## Prerequisites

Before you begin, ensure you have the following installed on your system:

- **C++ Compiler**: GCC or Clang is recommended.
- **CMake**: Version 3.10 or higher.
- **Git**: For cloning the repository.
- **Additional Libraries**: The project may depend on specific libraries (see below).

# Installing Dependencies

To successfully build and run **Break This Game**, you will need to install several dependencies depending on your platform. Below are instructions for installing the necessary libraries on Windows, macOS, and Linux.

## Windows

1. **Install a C++ Compiler**: You can use MinGW or Microsoft Visual Studio.
2. **Install CMake**: Download from [CMake's official website](https://cmake.org/download/).
3. **Install SFML**: Download the SFML package from [SFML's website](https://www.sfml-dev.org/download.php). Follow the provided installation instructions for your compiler.
4. **Install OpenAL**: Download the OpenAL installer from [OpenAL's website](https://openal.org/downloads/).
5. **Install GLM**: You can find GLM on [GitHub](https://github.com/g-truc/glm) and include the header files in your project.
6. **Install Lua**: Download Lua binaries from [Lua's official website](https://www.lua.org/download.html).
7. **Install ENet**: Clone the ENet repository from [GitHub](https://github.com/lsalzman/enet) and follow the instructions in the repository to build and include it in your project.

## macOS

1. **Install Xcode Command Line Tools**: Open the terminal and run: `xcode-select --install`
2. **Install Homebrew** (if not already installed): Run the following command in your terminal: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
3. **Install CMake**: `brew install cmake`
4. **Install SFML**: `brew install sfml`
5. **Install OpenAL**: `brew install openal-soft`
6. **Install GLM**: `brew install glm`
7. **Install Lua**: `brew install lua`
8. **Install ENet**: You may need to clone the repository and build it manually: 
   `git clone https://github.com/lsalzman/enet.git` 
   `cd enet` 
   `mkdir build` 
   `cd build` 
   `cmake ..` 
   `make`

## Linux

1. **Install a C++ Compiler**: Use g++ or clang. Install using your package manager: `sudo apt install build-essential`
2. **Install CMake**: `sudo apt install cmake`
3. **Install SFML**: `sudo apt install libsfml-dev`
4. **Install OpenAL**: `sudo apt install libopenal-dev`
5. **Install GLM**: `sudo apt install libglm-dev`
6. **Install Lua**: `sudo apt install liblua5.3-dev`
7. **Install ENet**: Clone the repository and build it: 
   `git clone https://github.com/lsalzman/enet.git` 
   `cd enet` 
   `mkdir build` 
   `cd build` 
   `cmake ..` 
   `make`

After installing the dependencies, you should be ready to compile and run **Break This Game**.

## Clone the Repository

```bash
git clone https://github.com/slammingprogramming/break-this-game.git
cd break-this-game

## Building the Project

1. Create a build directory:
```bash
mkdir build
cd build

2. Run CMake to configure the project:
```bash
cmake ..

3. Build the project:
make

## Running the Game
./break-this-game

If you encounter any issues, please refer to the documentation or open an issue in the GitHub repository.
