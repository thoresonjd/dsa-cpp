# File: Makefile
# Description: Global Makefile to build all programs and control dependencies.
# Author: Justin Thoreson
# Usage:
# - `make [all]`: Sets up the build directories and compiles all programs
# - `make <program>`: Compiles the specified program by calling its designated Makefile
# - `make setup`: Sets up the build directories
# - `make clean`: Removes the build directories

# Repo config
OBJ_DIR = ./obj
OUT_DIR = ./bin
BUILD_DIRS = $(OBJ_DIR) $(OUT_DIR)
MAKE_DIR = ./make
MAKE_EXT = mk

# Files
PROGRAMS = \
	queue \
	singly-linked-list \
	stack

all: $(PROGRAMS)

setup:
	mkdir -p $(BUILD_DIRS)

clean:
	rm -rf $(BUILD_DIRS)

.PHONY: all setup clean

$(PROGRAMS): setup
	make -f $(MAKE_DIR)/$@.$(MAKE_EXT)
