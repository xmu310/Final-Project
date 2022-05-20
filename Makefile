.IGNORE:all
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))
all: $(OBJ)
	./build_header.sh
	gcc main.c $(OBJ) -lm -o project
obj/%.o: src/%.c
	gcc -c $< -o $@
clean:
	rm -rf all.h project obj/*.o
