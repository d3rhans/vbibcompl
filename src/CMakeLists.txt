cmake_minimum_required(VERSION 3.10.0)

project(vbibcompl)

add_executable(vbibcompl main.cpp 
                         functions.cpp
                         ComplWord.cpp
                         ComplData.cpp
                         ProgramOptions.cpp
                         )

target_link_libraries(vbibcompl stdc++fs)
