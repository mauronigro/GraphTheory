PROGS = src/main.c src/init.c src/methods.c
OBJ = main

graph:
	gcc -o $(OBJ) $(PROGS)
