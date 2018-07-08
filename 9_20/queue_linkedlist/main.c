#include "queue.h"

int main(void)
{
	NODE *head = queue_create();

	if (head == NULL)
		return -1;

	int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
	int i;
	int data_de;

	for (i=0; i<sizeof(arr)/sizeof(*arr); i++)
	{
		queue_en(head, arr[i]);
	}

	queue_traverse(head);

	queue_de(head, &data_de);
	printf("data_de is %d\n", data_de);

	printf("==================\n");
	queue_traverse(head);

	queue_destroy(head);

	printf("==================\n");
	queue_traverse(head);



	return 0;
}
