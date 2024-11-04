# Installation Instructions

This document provides instructions for setting up the development environment for 'Break this Game'. Follow the steps below to ensure all necessary dependencies are installed and the project can be built successfully.

## Prerequisites

Before you begin, ensure you have the following installed on your system:

- **C++ Compiler**: GCC or Clang is recommended.
- **CMake**: Version 3.10 or higher.
- **Git**: For cloning the repository.
- **Additional Libraries**: The project may depend on specific libraries (see below).

## Dependencies

To install the required libraries, follow these commands based on your operating system:

### On Ubuntu

```bash
sudo apt-get update
sudo apt-get install build-essential cmake libsfml-dev

### On macOS

```bash
brew install cmake sfml

### On Windows
Download and install the required libraries manually or use a package manager like vcpkg.

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
