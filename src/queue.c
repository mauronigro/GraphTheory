#include "queue.h"
struct queue* queue_init()
{
	struct queue* f = malloc(sizeof *f);
	f->inicio = NULL;
	f->fim = NULL;
	f->qtd = 0;
	return f;
}

void queue_destroy(struct queue* f)
{
	struct node* no;
	while(no->proximo != NULL)
	{
		no = f->inicio;
		f->inicio = no->proximo;
		free(no);
	}
	free(f);
}
int queue_size(struct queue* f)
{	
	return f->qtd;
}

void enqueue(struct queue* f, int chave)
{
	struct node* novo_no = malloc(sizeof *novo_no);
	
	novo_no->dado = chave;
	novo_no->proximo = NULL;
	
	if(f->fim == NULL)
		f->inicio = novo_no;
	else
		f->fim->proximo = novo_no;
	
	f->fim = novo_no;
	f->qtd++;
}

int dequeue(struct queue* f)
{
	struct node* no_auxiliar = f->inicio;
	int valor = no_auxiliar->dado;
	f->inicio = no_auxiliar->proximo;
	if(f->inicio == NULL)
		f->fim = NULL;
	f->qtd--;
	free(no_auxiliar);
	return valor;
}

int queue_front(struct queue* f)
{
	return f->inicio->dado;
}
