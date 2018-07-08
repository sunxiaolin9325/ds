#include "queue.h"

int main(void)
{
	queue *l = NULL;
	int res = 0;
	int data = 0;
	int arr[] = {11,22,33,44,55,66,77,88,99};
	int i;

	l = queue_create();//创建队列

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		res = queue_en(l, arr[i]);//入队列
		if(res == -1)
		{
			printf("Queue Is Full!\n");
			break;
		}
	}

	queue_display(l);//遍历队列
	
	res = queue_de(l, &data);//出队列
	if(res == -1)
		printf("Queue Is Empty!\n");

	printf("======================\n");

	queue_display(l);//遍历队列
	
	queue_en(l, 9999);

	printf("======================\n");

	queue_display(l);//遍历队列

	queue_destroy(l);//销毁队列

	return 0;
}










