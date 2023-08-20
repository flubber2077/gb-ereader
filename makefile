export GBDK=/Users/Kyle/development/gameboy/gbdk
LCC = $(GBDK)/bin/lcc
FLAGS := -Wa-l -Wl-m -Wl-j -Wm-yn"E-Reader" -Wm-yo2 -Wm-yt0x19
TARGET := ./build
SOURCE := ./src
BIN = ./bin

all:
	$(LCC) $(FLAGS) -c -o ./bin/main.o ./src/main.c
	$(LCC) $(FLAGS) -o ./build/main.gb ./bin/main.o
	@echo "Game exported succesfully!"
	@echo "running game"
	open build/main.gb