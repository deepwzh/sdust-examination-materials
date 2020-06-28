cmake_minimum_required(VERSION 3.16)
project(Experiment2)

set(CMAKE_CXX_STANDARD 11)

include_directories("C:/Program Files (x86)/Parser Generator 2/Cpp/Include/")
#link_directories("D:/Compilation principle/CompileExperiment/UnxUtils/usr/local/lib")
link_libraries("C:/Program Files (x86)/Parser Generator 2/Cpp/Lib/msvc32/")

aux_source_directory("C:/Program Files (x86)/Parser Generator 2/Cpp/Source/" YACC_SRC)


add_executable(Experiment2  yacc.tab.c)