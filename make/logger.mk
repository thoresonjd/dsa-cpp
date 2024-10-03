INCLUDE_DIR = ./include
SRC_DIR = ./src
APP_DIR = ./examples
OBJ_DIR = ./obj
OUT_DIR = ./bin
CPP_FLAGS = -std=c++23 -Wall -Werror -pedantic -ggdb -O0 -I$(INCLUDE_DIR) 

logger: $(APP_DIR)/logger.cpp $(OBJ_DIR)/logger.o
	g++ $(CPP_FLAGS) $^ -o $(OUT_DIR)/$@

$(OBJ_DIR)/logger.o: $(SRC_DIR)/logger.cpp $(INCLUDE_DIR)/logger.h
	g++ $(CPP_FLAGS) $< -c -o $@
