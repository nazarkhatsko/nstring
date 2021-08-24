# name project
TAG := nstring

# name compiler
CC := gcc

# source parametres
SRC := $(wildcard *.c)

# flag parametres
CFLAG := -Wall
CFLAG += -std=c11
CFLAG += -I./

# mode list
.PHONY: release debug clean

# release mode
release: build/release/$(TAG)

build/release/$(TAG): $(SRC)
	@echo "[RELEASE]"
	@mkdir -p build/release/
	@$(CC) $(CFLAG) -O3 $^ -o $@

# debug mode
debug: build/debug/$(TAG)

build/debug/$(TAG): $(SRC)
	@echo "[DEBUG]"
	@mkdir -p build/debug/
	@$(CC) $(CFLAG) -g $^ -o $@

# clean mode
clean:
	@echo "[CLEAN]"
	@rm -r -f build/
