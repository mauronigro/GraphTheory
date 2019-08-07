#include "common.h"
struct node
{
	vertex w;
	struct node* next;
};

struct graph
{
	int V;
	int A;
	struct node** adj;
};

struct graph* graph_init(int V);
void graph_destroy(struct graph* G);
static struct node* new_node(vertex w, struct node* next);
void graph_insert_arc(struct graph* G, vertex v, vertex w);
void graph_remove_arc(struct graph* G, vertex v, vertex w);
void graph_show(struct graph* G);