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

void ugraph_insert_edge(struct graph* G, vertex v, vertex w)
{
    graph_insert_arc(G,v,w);
    graph_insert_arc(G,w,v);
}

void ugraph_remove_edge(struct graph* G, vertex v, vertex w)
{
    graph_remove_arc(G,v,w);
    graph_remove_arc(G,w,v);
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

int graph_in_degree(struct graph* G, vertex v)
{
    int degree = 0;
    for(vertex w = 0; w < G->V; w++)
    {
        if(G->adj[v][w] == 1)
            degree++;
    } 
    return degree;
}

int graph_out_degree(struct graph* G, vertex v)
{
    int degree = 0;
    for(vertex w = 0; w < G->V; w++)
    {
        if(G->adj[w][v] == 1)
            degree++;
    }
    return degree;
}

vertex* ugraph_degree(struct graph* G)
{
    vertex* degrees = malloc(G->V*sizeof(vertex));    
    
}

void graph_complete_build(struct graph* G)
{
    vertex v, w;
    for(v = 0; v < G->V; v++)
    {
        for(w = 0; w < G->V; w++)
        {
            if(v != w)
            {
              graph_insert_arc(G,v,w);
              graph_insert_arc(G,w,v); 
            } 
        }
    }
}

struct graph* graph_random(int V, int A)
{
    struct graph* G = graph_init(V);
    while(G->A < A)
    {
        vertex v = rand_vertex(G);
        vertex w = rand_vertex(G);
        if(v != w)
            graph_insert_arc(G, v, w);

    }
    return G;
}

struct graph* graph_dense_random(int V, int A)
{
    double prob =(double) A/(V*(V-1));
    struct graph* G = graph_init(V);
    for(vertex v = 0; v < G->V; v++)
        for(vertex w = 0; w < G->V; w++)
            if(v != w)
                if(rand () < prob*(RAND_MAX + 1.0))
                    graph_insert_arc(G,v,w); 
    return G;
}

vertex rand_vertex(struct graph* G)
{
	double r;
	r = rand() / (RAND_MAX + 1.0);
    return r * G->V;
}

bool graph_check_path(struct graph* G, int seq[G->V])
{
    bool flag = false;
    int i;
    for(i = 0; i < G->V - 1; i++)
    {
        if(G->adj[seq[i]][seq[i+1]] != 1)
            return false;
    }
    return true;
}

