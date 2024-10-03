OBJ_DIR = ./obj
OUT_DIR = ./bin
MAKE_DIR = ./make
MAKE_EXT = mk
LOG_FILE = ./log
PROGRAMS = logger

all: $(PROGRAMS)

setup:
	mkdir -p $(OBJ_DIR) $(OUT_DIR)

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR) $(LOG_FILE)

.PHONY: all setup clean

$(PROGRAMS): setup
	make -f $(MAKE_DIR)/$@.$(MAKE_EXT)

logger:

