# File: singly-linked-list.mk
# Description: Makefile to build the singly linked list test program.
# Author: Justin Thoreson
# Usage:
# - `make [singly-linked-list]`: Builds the singly linked list test program.

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
OBJS = $(OBJ_DIR)/singly-linked-list.o $(OBJ_DIR)/gtest.o

singly-linked-list: $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $(OUT_DIR)/$@

$(OBJ_DIR)/singly-linked-list.o: $(TEST_DIR)/singly-linked-list.cpp $(GTEST_INCLUDE_DIR)/gtest/gtest.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(OBJ_DIR)/gtest.o: 
	make -f $(MAKE_DIR)/gtest.$(MAKE_EXT)
