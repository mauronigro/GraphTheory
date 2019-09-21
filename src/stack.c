#include "stack.h"

struct stack* stack_init()
{
	struct stack* p = malloc(sizeof *p);
	p->topo = NULL;
	p->qtd = 0;
	
	return p;

}
void stack_destroy(struct stack* p)
{
	struct node* no_auxiliar;
	while(no_auxiliar->anterior != NULL)
	{
		no_auxiliar = p->topo;
		p->topo = no_auxiliar->anterior;
		free(no_auxiliar);
	}
	free(p);
}

int stack_size(struct stack* p)
{
	return p->qtd;
}

void push(struct stack* p, int key)
{
	struct node* novo_no = malloc(sizeof *novo_no);
	novo_no->dado = key;
	novo_no->anterior = p->topo;
	p->topo = novo_no;
	p->qtd++;	
}

int pop(struct stack* p)
{
	struct node* no_auxiliar;
	no_auxiliar = p->topo;
	p->topo = no_auxiliar->anterior;
	int valor = no_auxiliar->dado;
	free(no_auxiliar);
	p->qtd--;
	return valor;
}

int top(struct stack* p)
{
	return p->topo->dado;
}
