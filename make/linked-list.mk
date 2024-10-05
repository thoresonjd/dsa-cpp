# Repo config
INCLUDE_DIR = ./include
SRC_DIR = ./src
TEST_DIR = ./test
OBJ_DIR = ./obj
OUT_DIR = ./bin
MAKE_DIR = ./make
MAKE_EXT = mk

# GoogleTest directories
GTEST_DIR = ./external/googletest/googletest
GTEST_INCLUDE_DIR = $(GTEST_DIR)/include
GMOCK_DIR = ./external/googletest/googlemock
GMOCK_INCLUDE_DIR = $(GMOCK_DIR)/include

# C++
CXX = g++
CXX_FLAGS = \
	-std=c++23 -Wall -Werror -pedantic -ggdb -O0 \
	-I$(INCLUDE_DIR) -I$(SRC_DIR) \
	-I$(GTEST_DIR) -I$(GMOCK_DIR) \
	-I$(GTEST_INCLUDE_DIR) -I$(GMOCK_INCLUDE_DIR)

# Files
OBJS = $(OBJ_DIR)/linked-list.o $(OBJ_DIR)/gtest.o

linked-list: $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $(OUT_DIR)/$@

$(OBJ_DIR)/linked-list.o: $(TEST_DIR)/linked-list.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(OBJ_DIR)/gtest.o: 
	make -f $(MAKE_DIR)/gtest.$(MAKE_EXT)
