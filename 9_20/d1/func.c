#include "func.h"

NODE *llist_create()
{
	NODE *head = malloc(sizeof(NODE));

	if (head == NULL)
		return NULL;

	head->next = head;
	head->prev = head;
	return head; 
}

void llist_insert(NODE *head, NODE *data, int mode)
{
	NODE *p = head;
	NODE *new = malloc(sizeof(NODE));
	memcpy(new, data, sizeof(NODE));

	switch (mode)
	{
		case HEADINSERT:	
			new->next = p->next;
			new->prev = p;
			p->next->prev = new;
			p->next = new;
			break;
		case TAILINSERT:	
			new->next = p;
			new->prev = p->prev;
			p->prev->next = new;
			p->prev = new;
			break;
		default:
			free(new);
			printf("Mode error\n");
			break;
	}
}

void llist_traverse(NODE *head)
{
	NODE *p = head;

	if (p->next == head)
	{
		printf("No data\n");
		return;
	}

	do 
	{
		p = p->next;
		printf("%d\t%s\t%d\n", p->id, p->name, p->score);		
	} while (p->next != head);
}

void llist_destroy(NODE *head)
{
	NODE *p = head;
	NODE *q = NULL;

	while (p->next != head)
	{
		q = p->next;
		p->next = p->next->next;
		p->next->prev = p;
		free(q);
	}
	free(p);
	p = NULL;
}


NODE *llist_find(NODE *head, void *find_data)
{
	NODE *p = head;

	while (p->next != head)
	{
		p = p->next;

		if (p->id == *(int *)find_data
			|| !strcmp(p->name, find_data))
		{
			printf("%d\t%s\t%d\n", p->id, p->name, p->score);
			return p;	
		}
	}
	printf("No find\n");
	return NULL;
}

void llist_delete(NODE *head, void *find_data)
{
	NODE *q = llist_find(head, find_data);
	
	if (q == NULL)
		return;

	q->next->prev = q->prev;
	q->prev->next = q->next;
	free(q);
}












