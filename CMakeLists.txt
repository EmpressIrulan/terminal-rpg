cmake_minimum_required(VERSION 3.16)

project(terminal-rpg CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Keep binaries directly under build/, matching the layout CLAUDE.md
# documents (./build/terminal-rpg), regardless of which subdirectory
# a target is defined in.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_compile_options(-Wall -Wextra)

add_subdirectory(src)
