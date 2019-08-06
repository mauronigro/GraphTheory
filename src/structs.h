struct matrix_graph
{
	int V;
	int A;
	int** adj;
};

struct node
{
	vertex w;
	struct node* next;
};

struct list_graph
{
	int V;
	int A;
	struct node** adj;
};
