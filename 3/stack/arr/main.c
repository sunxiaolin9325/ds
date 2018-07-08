#include "stack.h"

int main(void)
{
	int arr[] = {11,22,33,44,55,66,77,88,99};
	int i, res;

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		res = stack_push(arr[i]);//入栈
		if(res == -1)
		{
			printf("Stack Is Full!\n");
			break;
		}
	}

	stack_display();//遍历栈
	
	res = stack_pop();	//出栈
	if(res == -1)
		printf("Stack Is Empty!\n");

	printf("出栈的数 : %d\n", res);

	stack_display();//遍历栈

	stack_push(arr[i]);

	stack_display();//遍历栈

	return 0;
}










