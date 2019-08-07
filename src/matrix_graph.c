#include "matrix_graph.h"
static int** matrix_init(int r, int c, int val)
{
	int** m = malloc(r*sizeof(int**));
	for(int i = 0; i < r; i++)
		m[i] = malloc(c*sizeof(int*));
	return m;
}

struct graph* graph_init(int V)
{
	struct graph* G = malloc(sizeof *G);
	G->V = V;
	G->A = 0;
	G->adj = matrix_init(V, V,0);
	return G;
}

static void destroy_matrix(int** m, int r)
{
	for(int i = 0; i < r; i++)
		free(m[i]);
	free(m);
}

void graph_destroy(struct graph* G)
{
	destroy_matrix(G->adj, G->V);
	free(G);
}


void graph_insert_arc(struct graph* G, vertex v, vertex w)
{
	if(G->adj[v][w] == 0)
	{
		G->adj[v][w] = 1;
		G->A++;
	}
}

void graph_remove_arc(struct graph* G, vertex v, vertex w )
{
	if(G->adj[v][w] == 1)
	{
		G->adj[v][w] = 0;
		G->A--;
	}
}


void graph_show(struct graph* G)
{
	for(vertex v = 0; v < G->V; v++)
	{	
		printf("%2d:", v);
		for(vertex w = 0; w < G->V; w++)
			if(G->adj[v][w] == 1)
				printf(" %2d", w);
		printf("\n");
	}
}

void  is_sink(struct graph* G)
{
    bool flag[G->V];
    for(vertex v = 0; v < G->V; v++)
        flag[v] = true;

    for(vertex v = 0; v < G->V; v++)
    {
        for(vertex w = 0; w < G->V; w++)
        {
            if(G->adj[v][w] == 1)
                flag[v] = false;
        }
    }
    printf("Sink:");
    for(vertex v = 0; v < G->V; v++)
        if(flag[v] == true)
            printf(" %d", v);
   printf("\n");
}

int graph_indeg(struct graph* G, vertex v)
{
    int degree = 0;
    for(vertex w = 0; w < G->V; w++)
    {
        if(G->adj[v][w] == 1)
            degree++;
    } 
    return degree;
}

int graph_oudeg(struct graph* G, vertex v)
{
    int degree = 0;
    for(vertex w = 0; w < G->V; w++)
    {
        if(G->adj[w][v] == 1)
            degree++;
    }
    return degree;
}
