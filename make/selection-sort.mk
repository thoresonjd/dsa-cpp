# File: selection-sort.mk
# Description: Makefile to build the selection sort test program.
# Author: Justin Thoreson
# Usage:
# - `make [selection-sort]`: Builds the selection sort test program.

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
OBJS = $(OBJ_DIR)/selection-sort.o $(OBJ_DIR)/gtest.o

selection-sort: $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $(OUT_DIR)/$@

$(OBJ_DIR)/selection-sort.o: $(TEST_DIR)/selection-sort.cpp $(GTEST_INCLUDE_DIR)/gtest/gtest.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(OBJ_DIR)/gtest.o:
	make -f $(MAKE_DIR)/gtest.$(MAKE_EXT)
