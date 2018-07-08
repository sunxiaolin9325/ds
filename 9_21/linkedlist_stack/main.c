#include "stack.h"

int main(void)
{
	int arr[] = {11,22,33,44,55,66,77,88,99};
	int i, res;

	llist *head = stack_create();

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		stack_push(head, &arr[i]);//入栈
	}

	stack_display(head);//遍历栈
	
	res = stack_pop(head);	//出栈
	if(res == -1)
		printf("Stack Is Empty!\n");

	printf("出栈的数 : %d\n", res);

	stack_display(head);//遍历栈
	printf("========================\n");

	stack_push(head, &arr[i]);

	stack_display(head);//遍历栈

	return 0;
}










