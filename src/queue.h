#include "common.h"
struct node{
	int dado;
	struct node* proximo;
};

struct queue{
	struct node* inicio;
	struct node* fim;
	int qtd;
};

struct queue* queue_init();
void queue_destroy(struct queue* f);
int queue_size(struct queue* f);
void enqueue(struct queue* f, int chave);
int dequeue(struct queue* f);
int queue_front(struct queue* f);
