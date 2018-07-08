#include "func.h"

PSTU headNode_create()
{
	PSTU pNode;

	pNode = malloc(sizeof(STU));
	if (pNode == NULL)
		return NULL;
	pNode->next = NULL;
}

void linkedList_insert(PSTU pHead, void *data, int mode)
{
	PSTU p = pHead;
	PSTU pNew = NULL;

	pNew = malloc(sizeof(STU));
	memcpy(pNew, data, sizeof(STU));
	pNew->next = NULL;

	switch (mode)
	{
		case 0:
			pNew->next = p->next;
			p->next = pNew;
			break;
		case 1:
			while (p->next != NULL)
				p++;
			p->next = pNew;
		default:
			printf("Input mode error\n");
			break;
	}
}

void linkedList_traverse(PSTU pHead)
{
	PSTU p = pHead->next;
	while (p != NULL)
	{
		printf("%d %s %f\n", p->id, p->name, p->score);
		p = p->next;
	}
}

void linkedList_destroy(PSTU pHead)
{
	PSTU p = pHead;
	PSTU q = p->next;

	while (q != NULL)
	{
		p->next = q->next;
		free(q);
		q = p->next;
	}
	free (p);
	p = NULL;
}

void linkedList_delete(PSTU pHead, void *data)
{
	PSTU p = linkedList_find(pHead, data);
	PSTU q = NULL;
	if (p == NULL)
	{
		printf("delete failed\n");
		return;
	}
	q = p->next;
	p->next = q->next;
	free(q);
}

PSTU linkedList_find(PSTU pHead, void *data)
{
	PSTU p = pHead;
	PSTU q = p->next;
	while (q != NULL)
	{
		if (q->id == *(int *)data || !strcmp(q->name, data))
		{
			printf("%d %s %f\n", q->id, q->name, q->score);
			return p;
		}
		p = q;
		q = q->next;
	}
	return NULL;
}
