#include "func.h"

int main(void)
{
	NODE	*head	= NULL;
	NODE	data;
	int		i;
	int		find_id	= 1001;
	char	*find_name	= "stu5";

	head = llist_create();

	if (head == NULL) 
		return -1;

	for (i=0; i<5; i++)
	{
		data.id = 1001 + i; 
		sprintf(data.name, "stu%d", i + 1);
		data.score = 100 * (i + 1);
		data.next = NULL;
		data.prev = NULL;
		llist_insert(head, &data, 1);
	}

	llist_traverse(head);
	printf("================\n");
#if 1
	llist_find(head, &find_id);
#else
	llist_find(head, find_name);
#endif
#if 1
	llist_delete(head, &find_id);
#else
	llist_delete(head, find_name);
#endif
	printf("================\n");
	llist_traverse(head);

	llist_destroy(head);

	printf("================\n");
	llist_traverse(head);

	






	return 0;
}
