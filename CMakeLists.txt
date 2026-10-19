cmake_minimum_required(VERSION 3.15)
project(15Puzzle)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(15Puzzle ${SOURCES})

target_include_directories(15Puzzle PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

