# File: binary-search-tree.mk
# Description: Makefile to build the binary search tree test program.
# Author: Justin Thoreson
# Usage:
# - `make [binary-search-tree]`: Builds the binary search tree test program.

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

# C++
CXX = g++
CXX_FLAGS = \
	-std=c++23 -Wall -Werror -pedantic -ggdb -O0 \
	-I$(INCLUDE_DIR) -I$(SRC_DIR) \
	-I$(GTEST_DIR) -I$(GTEST_INCLUDE_DIR)

# Files
OBJS = $(OBJ_DIR)/binary-search-tree.o $(OBJ_DIR)/gtest.o

binary-search-tree: $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $(OUT_DIR)/$@

$(OBJ_DIR)/binary-search-tree.o: $(TEST_DIR)/binary-search-tree.cpp $(GTEST_INCLUDE_DIR)/gtest/gtest.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(OBJ_DIR)/gtest.o: 
	make -f $(MAKE_DIR)/gtest.$(MAKE_EXT)
