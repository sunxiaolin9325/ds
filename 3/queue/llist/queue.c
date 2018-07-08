#include "queue.h"

queue *queue_create()
{
	return llist_create();
}

int queue_en(queue *l, int data)
{
	llist_insert(l, &data, 1);
}

void queue_display(queue *l)
{
	llist_display(l);
}

void queue_destroy(queue *l)
{
	llist_destroy(l);
}

int queue_de(queue *l, int *data)
{
	fetch(l, data);
}











