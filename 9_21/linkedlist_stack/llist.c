#include "llist.h"

llist *llist_create()
{
	llist *head = NULL;

	head = malloc(sizeof(llist));
	if(head == NULL)
		return NULL;
	head->next = head;
	head->prev = head;

	return head;
}

void llist_insert(llist *head, void *data, int mode)
{
	llist *p = head;
	llist *new = NULL;

	new = malloc(sizeof(llist));
	memcpy(new, data, sizeof(llist));
	
	switch(mode)
	{
		case HEADINSERT :
			new->next = p->next;
			new->prev = p->next->prev;
			p->next->prev = new;
			p->next = new;
			break;
		case TAILINSERT :
			new->prev = p->prev;
			new->next = p->prev->next;
			p->prev->next = new;
			p->prev = new;
			break;
		default :
			printf("Insert Mode Is Error!\n");
			return ;
	}
}

void llist_display(llist *head)
{
	llist *p = NULL;

	for(p = head->next; p != head; p = p->next)
		printf("%d ", p->id);
	printf("\n");
}

void llist_destroy(llist *head)
{
	llist *p = head->next;//	指向要释放的节点

	while(p != head)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
		p = head->next;
	}
	free(p);
	p = NULL;
}

int llist_delete(llist* head)
{
	int llist_de;
	llist *p = head->next;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	llist_de = p->id;
	free(p);
	p = NULL;
	return llist_de;
}


