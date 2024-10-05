# Repo config
OBJ_DIR = ./obj
OUT_DIR = ./bin
MAKE_DIR = ./make
MAKE_EXT = mk

# Files
PROGRAMS = linked-list

all: $(PROGRAMS)

setup:
	mkdir -p $(OBJ_DIR) $(OUT_DIR)

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)

.PHONY: all setup clean

$(PROGRAMS): setup
	make -f $(MAKE_DIR)/$@.$(MAKE_EXT)

linked-list:
