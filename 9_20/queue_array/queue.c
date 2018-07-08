#include "queue.h"


NODE *queue_create()
{
	NODE *p = malloc(sizeof(NODE));
	p->front = 0;
	p->tail = 0;
	return p;
}

int queue_en(NODE *p, int data)
{
	if (is_full(p))
		return -1;
	p->tail = (p->tail + 1) % QUEUESIZE;
	p->queue[p->tail] = data;
	return 0;
}

int is_full(NODE *p)
{
	if ((p->tail + 1) % QUEUESIZE == p->front)
		return 1;
	else 
		return 0;
}

void queue_traverse(NODE *p)
{
	int i = p->front;

	if (is_empty(p))
		return;

	while (i != p->tail)
	{
		i = (i + 1) % QUEUESIZE;
		printf("%d ", p->queue[i]);
	}
	printf("\n");
}

int is_empty(NODE *p)
{
	if (p->front == p->tail)
		return 1;
	else 
		return 0;
}

int queue_de(NODE *p)
{
	if (is_empty(p))	
		return -1;
	
	p->front++;

	return p->queue[p->front]; 
}

void queue_destroy(NODE *p)
{
	free(p);
}












