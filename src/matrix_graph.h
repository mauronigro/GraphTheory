#include "common.h"
#define vertex int

struct graph
{
	int V;
	int A;
	int** adj;
};

static int** matrix_init(int r, int c, int val);
struct graph* graph_init(int V);

static void destroy_matrix(int** m, int r);
void graph_destroy(struct graph* G);

void graph_insert_arc(struct graph* G, vertex v, vertex w);
void graph_remove_arc(struct graph* G, vertex v, vertex w);
void ugraph_insert_edge(struct graph* G, vertex v, vertex w);
void ugraph_remove_edge(struct graph* G, vertex v, vertex w);

void graph_show(struct graph* G);
void is_sink(struct graph* G);
int graph_indeg(struct graph* G, vertex v);
int graph_outdeg(struct graph* G, vertex v);
void graph_complete_build(struct graph* G);
struct graph* graph_random(int V, int A);
vertex rand_vertex(struct graph* G); 
bool graph_check_path(struct graph* G, int seq[G->V]);

