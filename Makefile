# File: Makefile
# Description: Global Makefile to build all programs and control dependencies.
# Author: Justin Thoreson
# Usage:
# - `make [all]`: Sets up the build directories and compiles all programs
# - `make <program>`: Compiles the specified program by calling its designated Makefile
# - `make setup`: Sets up the build directories (/obj and /bin)
# - `make clean`: Removes all object files and compiled binaries
# - `make vg-<program>`: Executes a program with Valgrind (assumes program is already compiled)

# Repo config
OBJ_DIR = ./obj
OUT_DIR = ./bin
BUILD_DIRS = $(OBJ_DIR) $(OUT_DIR)
MAKE_DIR = ./make
MAKE_EXT = mk

# Valgrind
VG = valgrind
VG_FLAGS = --leak-check=full --show-leak-kinds=all --track-fds=yes

# Files
PROGRAMS = \
	binary-search-tree \
	bubble-sort \
	circular-queue \
	insertion-sort \
	queue \
	selection-sort \
	singly-linked-list \
	stack

# Rules
all: $(PROGRAMS)

setup:
	mkdir -p $(BUILD_DIRS)

clean:
	rm -rf $(BUILD_DIRS)

.PHONY: all setup clean

$(PROGRAMS): setup
	make -f $(MAKE_DIR)/$@.$(MAKE_EXT)

vg-%:
	$(VG) $(VG_FLAGS) $(OUT_DIR)/$*

