######################################
# Declare some Makefile variables
CC = g++
COMPILER_FLAGS = -Wall -Wfatal-errors
LANG_STD = -std=c++17
INCLUDE_PATH = -I"./libs/" -I"./include"
LINKER=-llua5.4


OBJ_NAME = gameengine

######################################
# Makefile rules
# -llua5.4
build:
	g++ $(COMPILER_FLAGS) $(INCLUDE_PATH) $(LANG_STD) ./src/Main.cpp $(LINKER) -o main 

run:
	./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)