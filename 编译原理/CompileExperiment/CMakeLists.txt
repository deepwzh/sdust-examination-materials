cmake_minimum_required(VERSION 3.16)
project(CompileExperiment)

set(CMAKE_CXX_STANDARD 11)


#include_directories("C:/Program Files (x86)/Parser Generator 2/Cpp/Include")

#link_libraries("C:/Program Files (x86)/Parser Generator 2/Cpp/Lib/msvc32")

#aux_source_directory("C:/Program Files (x86)/Parser Generator 2/Cpp/Sources" YACC_SRCS)

add_subdirectory(Experiment3)

add_subdirectory(Experiment1)

add_subdirectory(Experiment4)

add_subdirectory(Experiment2)

aux_source_directory(src SRC)

add_executable(CompileExperiment ${SRC})