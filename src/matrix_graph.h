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


void graph_show(struct graph* G);
