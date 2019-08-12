#include "matrix_graph.h"

int main()
{
    struct graph* G = graph_init(3);
    graph_show(G);
    ugraph_insert_edge(G,0,1);
    graph_show(G);
    ugraph_remove_edge(G,0,1);
    graph_show(G);
    graph_destroy(G);
}

