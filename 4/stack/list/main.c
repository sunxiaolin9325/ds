#include "stack.h"

int main(void)
{
	stack *l = NULL; //指向数组
	int arr[] = {11,22,33,44,55,66,77,88,99};
	int i, res, save;

	l = stack_create();//创建栈
	
	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		res = stack_push(l, arr[i]);//入栈
		if(res == -1)
		{
			printf("Stack Is Full!\n");
			break;
		}
	}
	
	stack_display(l);//遍历栈

	res = stack_pop(l, &save);//出栈
	if(res == -1)
		printf("Stack Is empty!\n");

	stack_display(l);

	printf("======= save = %d\n", save);

	stack_push(l, arr[i]);
	
	stack_display(l);

	stack_destroy(l);//销毁栈

	return 0;
}













