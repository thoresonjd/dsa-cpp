# Repo config
OBJ_DIR = ./obj

# GoogleTest directories
GTEST_DIR = ./external/googletest/googletest
GTEST_INCLUDE_DIR = $(GTEST_DIR)/include
GTEST_SRC_DIR = $(GTEST_DIR)/src
GMOCK_DIR = ./external/googletest/googlemock
GMOCK_INCLUDE_DIR = $(GMOCK_DIR)/include
GMOCK_SRC_DIR = $(GMOCK_DIR)/src

# C++
CXX = g++
CXX_FLAGS = \
	-std=c++23 -Wall -Werror -pedantic -ggdb -O0 \
	-I$(GTEST_DIR) -I$(GMOCK_DIR) \
	-I$(GTEST_INCLUDE_DIR) -I$(GMOCK_INCLUDE_DIR)

# Files
OBJS = $(OBJ_DIR)/gtest.o $(OBJ_DIR)/gmock.o
GTEST_OBJS = $(OBJ_DIR)/gtest_main.o $(OBJ_DIR)/gtest-all.o
GMOCK_OBJS = $(OBJ_DIR)/gmock_main.o $(OBJ_DIR)/gmock-all.o

all: $(OBJS)

$(OBJ_DIR)/gtest.o: $(GTEST_OBJS)
	$(CXX) $(CXX_FLAGS) -r $^ -o $@

$(OBJ_DIR)/gtest_main.o: $(GTEST_SRC_DIR)/gtest_main.cc
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(OBJ_DIR)/gtest-all.o: $(GTEST_SRC_DIR)/gtest-all.cc
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(OBJ_DIR)/gmock.o: $(GMOCK_OBJS)
	$(CXX) $(CXX_FLAGS) -r $^ -o $@

$(OBJ_DIR)/gmock_main.o: $(GMOCK_SRC_DIR)/gmock_main.cc
	$(CXX) $(CXX_FLAGS) -c $< -o $@
	
$(OBJ_DIR)/gmock-all.o: $(GMOCK_SRC_DIR)/gmock-all.cc
	$(CXX) $(CXX_FLAGS) -c $< -o $@
	