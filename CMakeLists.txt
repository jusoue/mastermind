cmake_minimum_required(VERSION 3.21)
project(minesweeper)

set(CMAKE_CXX_STANDARD 20)

add_executable(mastermind
    src/main.cpp
    src/board.cpp
    src/row.cpp
)

add_subdirectory(lib/raylib)

target_link_libraries(mastermind
    PRIVATE
        raylib
)

target_include_directories(mastermind
    PRIVATE
        raylib
)