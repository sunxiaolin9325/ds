#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 6

typedef struct Node
{
	int queue[QUEUESIZE];
	int front;
	int tail;
} NODE;

NODE *queue_create();
int queue_en(NODE *, int);
int is_full(NODE *);
void queue_traverse(NODE *);
int is_empty(NODE *);
int queue_de(NODE *);
void queue_destroy(NODE *);








#endif
