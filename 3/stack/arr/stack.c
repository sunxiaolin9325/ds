#include "stack.h"

int stack_push(int data)
{
	if(isfull())
		return -1;
	stack[ind++] = data;
}

int stack_pop()
{
	if(isempty())
		return -1;
	return stack[--ind];
}

int isempty()
{
	return !ind;
}

int isfull()
{
	return !(ind - STACKSIZE);
}

void stack_display()
{
	int i;

	for(i = ind - 1; i >= 0; i--)
	{
		printf("  %d\n", stack[i]);
	}
	printf("--------\n");
}









