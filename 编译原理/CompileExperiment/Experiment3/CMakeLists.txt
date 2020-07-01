cmake_minimum_required(VERSION 3.16)
project(Experiment3)

aux_source_directory(header HEADER)
aux_source_directory(src SRC)

add_executable(Experiment3 main.cpp ${HEADER} ${SRC} src/Blank.cpp header/Blank.h)