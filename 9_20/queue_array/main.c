#include "queue.h"

int main(void)
{
	NODE *p = queue_create();
	int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
	int i;
	int res;
	int num_de;

	for (i=0; i<sizeof(arr)/sizeof(*arr); i++)
	{
		res = queue_en(p, arr[i]);
		if (res == -1)
		{
			printf("Queue is full\n");
			break;
		}
	}

	queue_traverse(p);

	num_de = queue_de(p);
	if (num_de != -1)
		printf("num_de is %d\n", num_de);
	else
		printf("Queue is empty\n");

	queue_traverse(p);

	queue_destroy(p);
	









	return 0;
}
















