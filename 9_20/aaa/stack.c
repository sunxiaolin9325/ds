#include "stack.h"

int stack_push(int *stack, int *p_ind, int data_push)
{
	if (*p_ind == STACKSIZE)
	{
		printf("Stack is full\n");
		return -1;
	}
	stack[*p_ind] = data_push;
	(*p_ind)++;
	return 0;
}

void stack_traverse(int *stack, int ind)
{
	if (ind == 0)
	{
		printf("Stack if empty\n");
		return;
	}

	while (ind)
	{
		ind--;
		printf("%d ", stack[ind]);
		printf("\n");
	}
}

int stack_pop(int *stack, int *p_ind)
{
	if (*p_ind == 0)
	{
		printf("Stack if empty\n");
		return -1;
	}

	(*p_ind)--;
	return stack[*p_ind];
}












