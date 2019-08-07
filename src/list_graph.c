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


void graph_show(struct graph* G)
{
	for(vertex v= 0; v < G->V; v++)
	{
		printf("%2d:", v);
		for(struct node* a = G->adj[v]; a != NULL; a = a->next)
			printf(" %2d", a->w);
		printf("\n");
	}
}
