.IGNORE: all debug

.PHONY: all debug clean 

SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,obj/%.o,$(SRC))

NORMAL_FLAGS := -lm
DEBUG_FLAGS := -Wall -lm

all: CFLAGS := $(NORMAL_FLAGS)
debug: CFLAGS := $(DEBUG_FLAGS)

all: $(OBJ)
	gcc main.c $(OBJ) $(CFLAGS) -o project
debug: $(OBJ)
	gcc main.c $(OBJ) $(CFLAGS) -o project

obj/%.o: src/%.c
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -rf project obj/*.o
