cmake_minimum_required(VERSION 3.15)
project(15Puzzle)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard (use  or 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Gather all your source files
file(GLOB SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# 2. Create your executable target (name it whatever you like)
add_executable(15Puzzle ${SOURCES})

# 3. Tell CMake where to find your header files automatically
target_include_directories(15Puzzle PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

