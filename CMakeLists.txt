cmake_minimum_required(VERSION 3.10)

# Project name
project(BreakThisGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Specify source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/lib/*.cpp")

# Include directories
include_directories(
    src/lib
    # Add additional include directories for dependencies if needed
)

# Find required packages (modify according to your setup)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(OpenAL REQUIRED)
find_package(GLM REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Lua REQUIRED)
find_package(ENet REQUIRED)

# Create executable
add_executable(break-this-game ${SOURCES})

# Link dependencies
target_link_libraries(break-this-game
    sfml-graphics
    sfml-window
    sfml-system
    OpenAL::OpenAL
    glm
    OpenGL::GL
    Lua::Lua
    ENet::ENet
)