#include "stack.h"

stack *stack_create()
{
	return llist_create();
}

int stack_push(stack *l, int data)
{
	llist_insert(l, &data, HEADINSERT);
}

void stack_display(stack *l)
{
	llist_display(l);
}

void stack_destroy(stack *l)
{
	llist_destroy(l);
}

int isempty(stack *l)
{
	return llist_ishead(l);
}

int stack_pop(stack *l, int *save)
{
	if(isempty(l))
		return -1;
	fetch(l, save);
}










