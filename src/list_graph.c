#include "list_graph.h"
struct graph* graph_init(int V)
{
	struct graph* G = malloc(sizeof * G);
	G->V = V;
	G->A = 0;
	G->adj = malloc(V*sizeof(struct node));
	for(vertex v = 0; v < G->V; v++)
		G->adj[v] = NULL;
	return G;
}

void graph_destroy(struct graph* G)
{
	free(G->adj);
	free(G);
}

static struct node* new_node(vertex w, struct node* next)
{
	struct node* a = malloc(sizeof(struct node));
	a->w = w;
	a->next = next;
	return a;
}

void graph_insert_arc(struct graph* G, vertex v, vertex w)
{
	for(struct node* a = G->adj[v]; a != NULL; a = a->next)
		if(a->w == w)
			return ;
	G->adj[v] = new_node(w, G->adj[v]);
	G->A++;
}

void graph_insert_edge(struct graph* G, vertex v, vertex w)
{
    graph_insert_arc(G, v, w);
    graph_insert_arc(G, w, v);
}

void graph_remove_arc(struct graph* G, vertex v, vertex w)
{
	for(struct node* a = G->adj[v]; a != NULL; a = a->next)
	{	
		if(a->w == w)
		{
			free(a);
			G->A--;
			return ;
		}
	}
}

void graph_remove_edge(struct graph* G, vertex v, vertex w)
{
    graph_remove_arc(G, v, w);
    graph_remove_arc(G, w, v);
}

void graph_show(struct graph* G)
{
    printf("Lista de Adjacencia:\n");
	for(vertex v= 0; v < G->V; v++)
	{
		printf("%2d:", v);
		for(struct node* a = G->adj[v]; a != NULL; a = a->next)
			printf(" %2d", a->w);
		printf("\n");
	}
}

void is_sink(struct graph* G)
{
    bool flag[G->V];
    for(vertex v = 0; v < G->V; v++)
        flag[v] = true;
    struct node* a;
    for(vertex v = 0; v < G->V; v++)
    {
        if(G->adj[v]->next == NULL)
            flag[v] = false;
    }
    printf("Sink:");
    for(vertex v = 0; v < G->V; v++)
        if(flag[v] == true)
            printf(" %d", v);
        printf("\n");    
}

int graph_degree(struct graph* G, vertex v)
{
    int degree = 0;
    for(struct node* a = G->adj[v]; a != NULL; a = a->next)
        degree++;
    return degree;
}

void graph_cycle_outher(struct graph* G)
{
    for(int i = 0; i < (G->V-1)/2; i++)
    {
       graph_insert_edge(G, i, i+1);
    }
    graph_insert_edge(G, 0, (G->V -1)/2);
}

void graph_connect(struct graph* G)
{
    for(int i = 0; i <= (G->V-1)/2; i++)
    {
        graph_insert_edge(G, i, i + (G->V)/2);
    }
}

void graph_petersen_gen(struct graph* G, int k)
{
    if(G->V > 2*k)
    {
        printf("Gerando Petersen Generalizado G(%d, %d)\n", G->V/2, k);
        graph_cycle_outher(G);
        graph_connect(G);
        for(int i = 0; i < G->V/2; i++)
        {
            if(G->V/2 + i + k <= G->V-1)
            {
                graph_insert_edge(G, G->V/2 + i, G->V/2 + i + k);
            }
            else
            { 
                int resto  = (G->V/2 +i + k) % G->V;
                graph_insert_edge(G, G->V/2 + i, G->V/2 + resto);
            }

        }
    }
    else
    {
        printf("Necessario que, n > k, %d > %d  \n", G->V, k);
    }
}
