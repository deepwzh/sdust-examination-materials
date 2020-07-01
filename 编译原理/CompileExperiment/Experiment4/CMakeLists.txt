project(Experiment4)

aux_source_directory(header HEADER)
aux_source_directory(src SRC)

add_executable(Experiment4 main.cpp ${HEADER} ${SRC})