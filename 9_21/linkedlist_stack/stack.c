#include "stack.h"

llist *stack_create()
{
	return llist_create();
}

void stack_push(llist *head, int *data)
{
	llist_insert(head, data, 0);
}

int stack_pop(llist *head)
{
	if(isempty(head))
		return -1;
	
	return llist_delete(head);
}

int isempty(llist *head)
{
	if (head->next == head)	
		return 1;
	else 
		return 0;
}

void stack_display(llist* head)
{
	llist_display(head);
}

void stack_destroy(llist *head)
{
	llist_destroy(head);
}

