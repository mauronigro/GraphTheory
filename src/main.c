#include "matrix_graph.h"

int main()
{
	struct graph* G = graph_init(3);
	graph_insert_arc(G,0,1);
	graph_insert_arc(G,0,2);
    graph_insert_arc(G,1,0);
	graph_show(G);
	is_sink(G);
    int indeg = graph_indeg(G,0);
    printf("Teste:%d\n", indeg);
    graph_destroy(G);
}
