cmake_minimum_required(VERSION 3.29)
project(Log_File_Analyzer C)

set(CMAKE_C_STANDARD 11)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

include_directories(${SRC_DIR} ${INCLUDE_DIR})

add_executable(Log_File_Analyzer
        src/main.c
        src/log_entry.c
        include/log_entry.h
        src/search.c
        include/search.h
        src/utils.c
        include/utils.h
)

target_link_libraries(Log_File_Analyzer PRIVATE -static -static-libgcc -static-libstdc++ pthread)
