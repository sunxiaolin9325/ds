#include "func.h" 

int main(void)
{
	STU data;
	STU *head = NULL; 
	int i;
	int find_id = 1002;
	char *find_name = "stu2";

	head = linkedlist_create();

	for (i = 0; i < 5; i++)
	{
		data.id = 1001 + i;
		sprintf(data.name, "stu%d", i + 1);
		data.score = 100 * (i + 1);
		linkedlist_insert(head, &data, 1);
	}

	linkedlist_traverse(head);
	
	linkedlist_delete(head, &find_id);
	printf("====================\n");
	linkedlist_traverse(head);

	linkedlist_destroy(head);



	return 0;
}
