#include "stack.h"

stack *stack_create()
{
	stack *l = NULL;

	l = malloc(sizeof(stack));
	/*if error*/
	l->ind = 0;

	return l;
}

int isfull(stack *l)
{
	return !(l->ind - BUFSIZE);
}

int stack_push(stack *l, int data)
{
	if(isfull(l))
		return -1;
	l->buf[l->ind++] = data;
}

void stack_display(stack *l)
{
	int i;

	for(i = l->ind - 1; i >= 0; i--)
	{
		printf("	%d\n",l->buf[i]);
	}
	printf("-----------\n");
}

void stack_destroy(stack *l)
{
	free(l);
}

int isempty(stack *l)
{
	return !(l->ind);
}

int stack_pop(stack *l, int *save)
{
	if(isempty(l))
		return -1;
	l->ind--;
	*save = l->buf[l->ind];
}










