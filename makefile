SRC = src/main.c src/list_graph.c src/queue.c src/stack.c
BIN = main
BIN_DIR = bin/
all:
	gcc -o $(BIN_DIR)$(BIN) $(SRC)
	./$(BIN_DIR)$(BIN) 10 4
