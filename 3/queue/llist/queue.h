#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

#define BUFSIZE 6

typedef llist queue;

queue *queue_create();

int queue_en(queue *l, int data);

void queue_display(queue *l);

void queue_destroy(queue *l);

int queue_de(queue *l, int *data);

#endif









