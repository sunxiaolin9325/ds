#include "stack.h"

void stack_push(int push_data)
{
	if (is_full())
	{
		printf("Stack is full\n");
		return;
	}

	stack[stack_top] = push_data;
	stack_top++;
}

int is_full()
{
	if (stack_top == STACK_LEN)
		return 1;
	else
		return 0;
}

int stack_pop()
{
	if (is_empty())
	{
		printf("Stack is empty\n");
		return -1;
	}
	
	stack_top--;
	return stack[stack_top];
}

int is_empty()
{
	if (stack_top == 0)
		return 1;
	else
		return 0;
}

void stack_traverse()
{
	int i = stack_top;

	while (i != 0)
	{
		i--;
		printf("%d\n", stack[i]);
	}
}
