#include "func.h"

int main(void)
{
	STU *head = malloc(sizeof(STU));
	if (head == NULL)
		return -1;
	head->next = head;

	STU data;
	int i;
	int mode;

	for (i = 0; i < 5; i++)
	{
		data.id = 1001 + i;
		sprintf(data.name, "stu%d", i + 1);
		data.score = 100 * (i + 1);
//		llist_insert(head, &data, 1);
		
		STU *new = malloc(sizeof(STU));
		memcpy(new, &data, sizeof(STU));
		new->next = NULL;
		STU *p = head;

		mode = 1;
		switch (mode)
		{
			case 0:
				new->next = p->next;
				p->next = new;
				break;
			case 1:
				while (p->next != head)
					p = p->next;
				new->next = p->next;
				p->next = new;
				break;
			default:
				printf("Mode error");
				break;
		}
	
	}

	llist_traverse(head);

	llist_destroy(head);







	return 0;
}
