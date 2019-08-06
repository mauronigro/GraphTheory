#include "methods.h"

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
