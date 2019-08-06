#include "methods.h"
/*Metodos para as matrizes de adjacencia*/
void matrix_graph_insert_arc(struct matrix_graph* G, vertex v, vertex w)
{
	if(G->adj[v][w] == 0)
	{
		G->adj[v][w] = 1;
		G->A++;
	}
}

void matrix_graph_remove_arc(struct matrix_graph* G, vertex v, vertex w )
{
	if(G->adj[v][w] == 1)
	{
		G->adj[v][w] = 0;
		G->A--;
	}
}


void matrix_graph_show(struct matrix_graph* G)
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



/*Metodos para as listas de adjacencias*/
static struct node* new_node(vertex w, struct node* next)
{
	struct node* a = malloc(sizeof(struct node));
	a->w = w;
	a->next = next;
	return a;
}

void list_graph_show(struct list_graph* G)
{
	for(vertex v= 0; v < G->V; v++)
	{
		printf("%2d:", v);
		for(struct node* a = G->adj[v]; a != NULL; a = a->next)
			printf(" %2d", a->w);
		printf("\n");
	}
}


