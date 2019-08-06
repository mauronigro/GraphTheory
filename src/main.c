#include "main.h"

int main()
{
	struct matrix_graph* G = matrix_graph_init(3);
	struct list_graph* H = list_graph_init(5);
	matrix_graph_show(G);
	list_graph_show(H);
	matrix_graph_destroy(G);
	list_graph_destroy(H);
}
