#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 6

typedef struct node
{
	int buf[BUFSIZE];
	int ind;
}stack;

stack *stack_create();

int stack_push(stack *l, int data);

void stack_display(stack *l);

void stack_destroy(stack *l);

int stack_pop(stack *l, int *save);

#endif






