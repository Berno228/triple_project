cmake_minimum_required(VERSION 2.8)

project(pytnashki)

set(SOURCE_EXE startAndPrint.cpp swapElements.cpp victoryAndMain.cpp)

set(SOURCE_LIB pythashki.h)

add_library(pythashki STATIC ${SOURCE_LIB})

add_executable(startt ${SOURCE_EXE})

target_link_libraries(startt pythashki)
