#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
} NODE;

NODE *queue_create();
void queue_en(NODE *, int);
void queue_traverse(NODE *);
void queue_de(NODE *, int *);
void queue_destroy(NODE *);










#endif
