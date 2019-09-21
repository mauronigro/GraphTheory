#include "list_graph.h" 
int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);  
    n = 2*n;
    int k = atoi(argv[2]);
    struct graph* G = graph_init(n);
    graph_petersen_gen(G, k);
    graph_show(G);
    graph_destroy(G);
}
