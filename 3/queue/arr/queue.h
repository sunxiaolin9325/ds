#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 6

typedef struct node
{
	int buf[BUFSIZE];
	int front;
	int tail;
}queue;

queue *queue_create();

int queue_en(queue *l, int data);

void queue_display(queue *l);

void queue_destroy(queue *l);

int queue_de(queue *l, int *data);

#endif









