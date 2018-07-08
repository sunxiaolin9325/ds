#include "func.h"

void llist_traverse(STU *head)
{
	STU *p = head;

	while (p->next != head)
	{
		p = p->next;
		printf("%d\t%s\t%d\n", p->id, p->name, p->score);
	}
}

void llist_destroy(STU *head)
{
	
}
