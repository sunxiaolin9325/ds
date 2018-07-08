#include "func.h"

STU *linkedlist_create()
{
	STU *head = malloc(sizeof(STU));
	if (head == NULL)
		return NULL;
	head->next = head;
	return head;
}

void linkedlist_insert(STU *head, void *data, int mode)
{
	STU *p = head;
	STU *new = malloc(sizeof(STU));
	memcpy(new, data, sizeof(STU));
	new->next = NULL;
	switch (mode)
	{
		case HEADINSERT:
			new->next = p->next;
			p->next = new;
			break;
		case TAILINSERT:
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

void linkedlist_traverse(STU *head)
{
	STU *p = head;
	
	while (p->next != head)
	{
		p = p->next;
		printf("%d\t%s\t%.2f\n", p->id, p->name, p->score);
	}
}

void linkedlist_destroy(STU *head)
{
	STU *p = head;
	STU *q = p->next;

	while (p->next != head)
	{
		p->next = q->next;
		free(q);
		q = p->next;	
	}
	free(p);
	p = NULL;
}

void linkedlist_delete(STU *head, void *find_data)
{
	STU *p = NULL;
	STU *q = linkedlist_find(head, find_data); 
	if (q == NULL)
	{
		printf("Delete failed\n");
		return;
	}
	p = q->next;
	q->next = p->next;
	free(p);
	p = NULL;
}

STU *linkedlist_find(STU *head, void *find_data)
{
	STU *p = head;
	STU *q = p->next;

	while (p->next != head)
	{
		if (q->id == *(int *)find_data || !strcmp(q->name, find_data))
		{
			printf("%d\t%s\t%.2f\n", q->id, q->name, q->score);
			return p;
		}
		p = q;
		q = q->next;
	}
	return NULL;
}














