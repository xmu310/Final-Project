.IGNORE:all
SRC = $(wildcard src/Andy/*.c src/Anting/*.c)
OBJ = $(SRC:h=o)
all: $(OBJ)
	./build_header.sh
	gcc main.c $(OBJ) -lm -o project
obj/%.o: src/%.c
	gcc -c $< -o $@
clean:
	rm -rf all.h project obj/Andy/*.o obj/Anting/*.o
