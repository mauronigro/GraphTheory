#include "common.h"
struct node
{
	int dado;
	struct node* anterior;
};

struct stack
{
	struct node* topo;
	int qtd;
};


struct stack* stack_init();
void stack_destroy(struct stack* p);
int stack_size(struct stack* p);
void push(struct stack* p, int key);
int pop(struct stack* p);
int top(struct stack* p);

