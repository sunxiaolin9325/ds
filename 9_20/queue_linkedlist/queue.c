#include "queue.h"

NODE *queue_create()
{
	NODE *head = malloc(sizeof(NODE));
	if (head == NULL)
		return NULL;
	head->next = head;
	head->prev = head;
	return head;
}

void queue_en(NODE *head, int data)
{
	NODE *p = head;
	NODE *new = malloc(sizeof(NODE));
	new->data = data;
	new->next = p;
	new->prev = p->prev;
	p->prev->next = new;
	p->prev = new;
}

void queue_traverse(NODE *head)
{
	NODE *p = head;

	while (p->next != head)	
	{
		printf("++++++");
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

void queue_de(NODE *head, int *data_de)
{
	NODE *p = head;
	
	if (p->next == head)
	{
		printf("No data\n");
		return;
	}

	NODE *q = p->next;
	p->next = q->next;
	p->next->prev = p;
	*data_de = q->data;
	free(q);
}

void queue_destroy(NODE *head)
{
	NODE *p = head;
	NODE *q = NULL;

	while (p->next != head)
	{
		q = p->next;
		p->next = q->next;
		p->next->prev = p;
		free(q);
	}
	free(head);
}







