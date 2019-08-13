SRC_MATRIX = src/main_matrix.c src/matrix_graph.c src/queue.c
SRC_LIST = src/main_list.c src/list_graph.c
BIN_MATRIX = main_matrix
BIN_LIST = main_list
BIN_DIR = bin/
matrix:
	gcc -o $(BIN_DIR)$(BIN_MATRIX) $(SRC_MATRIX)
list:
	gcc -o $(BIN_DIR)$(BIN_LIST) $(SRC_LIST)
