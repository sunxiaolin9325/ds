#include "queue.h"

queue *queue_create()
{
	queue *l = NULL;

	l = malloc(sizeof(queue));
	/*if error*/
	l->front = l->tail = 0;

	return l;
}

int queue_en(queue *l, int data)
{
	if((l->tail + 1) % BUFSIZE == l->front)
		return -1;
	l->tail = (l->tail + 1) % BUFSIZE;
	l->buf[l->tail] = data;
}

void queue_display(queue *l)
{
	int i;
	if(l->front == l->tail)
		return ;
	i = (l->front + 1) % BUFSIZE;
	
	//用do while
	while(i != l->tail)
	{
		printf("%d	", l->buf[i]);
		i = (i + 1) % BUFSIZE;
	}
	printf("%d\n", l->buf[i]);
}

void queue_destroy(queue *l)
{
	free(l);
}

int queue_de(queue *l, int *data)
{
	if(l->front == l->tail)
		return -1;
	l->front = (l->front + 1) % BUFSIZE;
	
	*data = l->buf[l->front];
}











