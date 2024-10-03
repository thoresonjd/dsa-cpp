INCLUDE_DIR = ./include
SRC_DIR = ./src
APP_DIR = ./examples
OBJ_DIR = ./obj
OUT_DIR = ./bin
CPP_FLAGS = -std=c++23 -Wall -Werror -pedantic -ggdb -O0 -I$(INCLUDE_DIR) -I$(SRC_DIR)

linked-list: $(OBJ_DIR)/linked-list.o $(OBJ_DIR)/logger.o
	g++ $(CPP_FLAGS) $^ -o $(OUT_DIR)/$@

$(OBJ_DIR)/linked-list.o: $(APP_DIR)/linked-list.cpp $(INCLUDE_DIR)/logger.h
	g++ $(CPP_FLAGS) $< -c -o $@

$(OBJ_DIR)/logger.o: $(SRC_DIR)/logger.cpp $(INCLUDE_DIR)/logger.h
	g++ $(CPP_FLAGS) $< -c -o $@
