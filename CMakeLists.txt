cmake_minimum_required(VERSION 3.10)
project(LogMiner11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(include)

add_executable(logminer
    src/main.cpp
    src/app.cpp
    src/file_scanner.cpp
    src/text_file.cpp
    src/text_stats.cpp
    src/stats_report.cpp
    src/tokenizer.cpp
)