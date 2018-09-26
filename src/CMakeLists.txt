cmake_minimum_required(VERSION 3.10.0)

project(vbibcompl)

add_executable(vbibcompl 
                    main.cpp 
                    BibFiles.cpp
                    ProgramOptions.cpp
              )

target_link_libraries(vbibcompl stdc++fs)

install(TARGETS vbibcompl DESTINATION bin)
