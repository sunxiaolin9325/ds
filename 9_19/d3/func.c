#include "func.h"

STU *llist_create(int num)
{
	int i = 0;
	STU *first = malloc(sizeof(STU));
	STU *p = first;
	p->id = 1001 + i;
	sprintf(p->name, "stu%d", i + 1);
	p->score = 100 * (i + 1);
	p->next = p;

	for (i = 1; i < NUM; i++)
	{
		STU *new = malloc(sizeof(STU));
		new->id = 1001 + i;
		sprintf(new->name, "stu%d", i + 1);
		new->score = 100 * (i + 1);
		new->next = p->next;
		p->next = new;
		p = p->next;
	}
	return first; 
}

void llist_traverse(STU *first)
{
	STU *p = first;

	do
	{
		printf("%d\t%s\t%d\n", p->id, p->name, p->score);
		p = p->next;
	} while (p != first);
}

void llist_destroy(STU *first)
{
	STU *p = first;
	STU *q = p->next;

	while (q != first)
	{
		p->next = q->next;
		free(q);
		q = p->next;
	}
	free(first);
	p = NULL;
}

/*
STU *llist_find(STU *first, void *find_data)
{
	STU *p = first;
	STU *q = p->next;
	flag = 0;

	while (p != NULL)
	{
		if (first->id == *(int *)find_data || !strcmp(first->name, find_data))	
		{
			printf("%d\t%s\t%d\n", p->id, p->name, p->score);
			flag = 1;
			return p;
		}
		else if (q->id == *(int *)find_data || !strcmp(q->name, find_data))	
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

void llist_delete(STU **pfirst, void *find_data)
{
	STU *p = llist_find(*pfirst, find_data);
	STU *q = NULL;

	if (p == NULL)
		return;
	if (flag == 1)
	{
		*pfirst = p->next;
		free(p);
		p = NULL;
	}
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		q = NULL; 
	}
}
*/
STU *llist_find(STU *first, void *find_data)
{
	STU *p = first;

	do
	{
		if (p->id == *(int *)find_data || !strcmp(p->name, find_data))	
		{
			printf("%d\t%s\t%d\n", p->id, p->name, p->score);
			return p;
		}
		p = p->next;
	} while (p != first);
	printf("No find\n");
	return NULL;
}

void llist_delete(STU **pfirst, void *find_data)
{
	STU *p = llist_find(*pfirst, find_data);
	STU *q = *pfirst;

	if (p == NULL)
		return;
	if (p == *pfirst)
	{
		*pfirst = p->next;
		while (q->next != p)
			q = q->next;
		q->next = p->next; 
		free(p);
		p = NULL;
	}
	else
	{
		while (q->next != p)
			q = q->next;
		q->next = p->next;
		free(p);
		p = NULL; 
	}
}


