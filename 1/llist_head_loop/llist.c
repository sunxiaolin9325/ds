#include "llist.h"

llist *llist_create()
{
	llist *head = NULL;

	head = malloc(sizeof(llist));
	if(head == NULL)
		return NULL;
	head->next = head;

	return head;
}

void llist_insert(llist *head, void *data, int mode)
{
	llist *new = NULL;
	llist *p = head;

	new = malloc(sizeof(llist));
	memcpy(new, data, sizeof(llist));
	new->next = NULL;
	
	switch(mode)
	{
		case HEADINSERT :
				new->next = p->next;
				p->next = new;
				break;
		case TAILINSERT :
				while(p->next != head)
					p = p->next;
				new->next = p->next;
				p->next = new;
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
		printf("%d	%s	%d\n", p->id, p->name, p->math);
}

void llist_destroy(llist *head)
{
	llist *back = head;
	llist *p = head->next;

	while(p != head)
	{
		back->next = p->next;
		free(p);
		p = back->next;
	}
	free(back);
	back = NULL;
}

void llist_delete(llist *head, void *find_data)
{
	llist *back = NULL;
	llist *p = NULL;

	back = llist_find(head, find_data);
	if(back == NULL)
	{
		printf("Delete It Is Failed!\n");
		return ;
	}
	p = back->next;
	back->next = p->next;
	free(p);
	p = NULL;
}

llist *llist_find(llist *head, void *find_data)
{
	llist *back = head;
	llist *p = head->next;

	while(p != head)
	{
		if(p->id == *(int *)find_data || 
		  !strcmp(p->name, find_data))
		{
			printf("Find It!\n");
			printf("###%d	%s	%d\n", p->id, p->name, p->math);
			return back;
		}
		back = p;
		p = p->next;
	}
	printf("Not Find It!\n");
	return NULL;
}










