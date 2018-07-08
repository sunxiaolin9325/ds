#include <stdio.h>
#include "repolish.h"

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

int isfull()
{
	return !(ind - STACKSIZE);
}

int isempty()
{
	return !ind;
}

void stack_display()
{
	int i;

	for(i = ind - 1; i >= 0; i--)
	{
		printf("  %d\n", stack[i]);
	}
	printf("----------\n");
	getchar();
}











