######################################
# Declare some Makefile variables
CC = g++
COMPILER_FLAGS = -Wall -Wfatal-errors
LANG_STD = -std=c++17
INCLUDE_PATH = -I"./libs/"
SRC_FILES = src/*.cpp	src/Game/*.cpp src/Logger/*.cpp
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.3
OBJ_NAME = gameengine

######################################
# Makefile rules
build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) \
	$(INCLUDE_PATH) \
	$(SRC_FILES) \
	$(LINKER_FLAGS) \
	-o $(OBJ_NAME)

run:
	./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)