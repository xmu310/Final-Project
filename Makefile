.IGNORE:all
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))
all: $(OBJ)
	gcc main.c $(OBJ) -lm -o project
obj/%.o: src/%.c
	gcc -c $< -o $@
clean:
	rm -rf project obj/*.o
