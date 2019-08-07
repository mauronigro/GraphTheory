PROG_MATRIX = src/main.c src/matrix_graph.c
PROG_LIST = src/main.c src/list_graph.c
OBJ_MATRIX = main_matrix
OBJ_LIST = main_list
matrix:
	gcc -o $(OBJ_MATRIX) $(PROG_MATRIX)
list:
	gcc -o $(OBJ_LIST) $(PROG_LIST)
