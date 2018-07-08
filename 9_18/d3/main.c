#include "func.h" 

int main(void)
{
	STU data;
	int i;
	int find_id = 1006;
	char *find_name = "stu3";
	STU *head = llist_create();
	if (head == NULL)
		return -1;

	for (i = 0; i < 5; i++)
	{
		data.id = 1001 + i;
		sprintf(data.name, "stu%d", i + 1);
		data.score = 100 * (1 + i);
		llist_insert(head, &data, 1);
	}

	llist_traverse(head);

	llist_find(head, &find_id);

	llist_delete(head, find_name);

	printf("========================\n");
	llist_traverse(head);

	llist_destroy(head);
	printf("========================\n");
	llist_traverse(head);


	return 0;
}
