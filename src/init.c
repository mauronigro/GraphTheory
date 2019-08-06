#include "init.h"
/*Inicializa e destroi matriz de adjacencia*/
static int** matrix_init(int r, int c, int val)
{
	int** m = malloc(r*sizeof(int**));
	for(int i = 0; i < r; i++)
		m[i] = malloc(c*sizeof(int*));
	return m;
}

struct matrix_graph* matrix_graph_init(int V)
{
	struct matrix_graph* G = malloc(sizeof *G);
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

void matrix_graph_destroy(struct matrix_graph* G)
{
	destroy_matrix(G->adj, G->V);
	free(G);
}
/*Inicializa e destroi lista de adjacencia*/
static struct node* new_node(vertex w, struct node* next)
{
	struct node* a = malloc(sizeof(struct node));
	a->w = w;
	a->next = next;
	return a;
}

struct list_graph* list_graph_init(int V)
{
	struct list_graph* G = malloc(sizeof * G);
	G->V = V;
	G->A = 0;
	G->adj = malloc(V*sizeof(struct node));
	for(vertex v = 0; v < G->V; v++)
		G->adj[v] = NULL;
	return G;
}

void list_graph_destroy(struct list_graph* G)
{
	free(G->adj);
	free(G);
}
