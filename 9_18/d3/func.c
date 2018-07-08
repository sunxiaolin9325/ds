#include "func.h"

STU *llist_create()
{
	STU *head = malloc(sizeof(STU));
	if (head == NULL)
		return NULL;
	return head;
}

void llist_insert(STU *head, STU *data, int mode)
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
			while (p->next != NULL)
				p = p->next;
			new->next = p->next;
			p->next = new;
			break;
		default:
			printf("Mode error");
			break;
	}
}

void llist_traverse(STU *head)
{
	STU *p = head;
	while (p->next != NULL)
	{
		p = p->next;
		printf("%d\t%s\t%d\n", p->id, p->name, p->score);
	}
}

STU *llist_find(STU *head, void *find_data)
{
	STU *p = head;
	STU *q = p->next;

	while (q != NULL)
	{
		if (q->id == *(int *)find_data || !strcmp(q->name, find_data))
		{
			printf("%d\t%s\t%d\n", q->id, q->name, q->score);
			return p;
		}
		p = q;
		q = q->next;
	}
	printf("No find\n");
	return NULL;
}

void llist_delete(STU *head, void *find_data)
{
	STU *p = NULL;
	STU *q = llist_find(head, find_data);
	if (q == NULL)
		return;
	p = q->next;
	q->next = p->next;
	free(p);
	p = NULL;
}

void llist_destroy(STU *head)
{
	STU *p = head;
	STU *q = p->next;

	while (q != NULL)
	{
		p->next = q->next;
		free(q);
		q = p->next;
	}
	free(p);
	p = NULL;
}


















