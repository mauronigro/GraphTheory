#include "matrix_graph.h"

int main()
{
    struct graph* G = graph_init(5);
    graph_insert_arc(G, 0, 1);
    graph_insert_arc(G, 0, 2);
    graph_insert_arc(G, 0, 3);
    int degree = graph_indeg(G, 0);
    printf("%d\n", degree);
    graph_destroy(G);
}

