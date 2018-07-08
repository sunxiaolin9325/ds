#include "stack.h"

int main(void)
{
	int stack[STACKSIZE];
	int ind = 0;
	int i;
	int res;
	int data_pop;
	int data[] = {-1, 22, -1, 44, 55, -1, 77, 88, 99};

	for (i=0; i<sizeof(data)/sizeof(*data); i++)
	{
		res = stack_push(stack, &ind, data[i]);
		if (res == -1)
		{
			break;
		}
	}	

	stack_traverse(stack, ind);

	data_pop = stack_pop(stack, &ind);
	printf("data_pop id %d\n", data_pop);
	
	printf("=======================\n");
	stack_traverse(stack, ind);



	return 0;
}
