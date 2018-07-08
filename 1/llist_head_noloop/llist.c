#include "llist.h"

llist *llist_create()
{
	llist *head = NULL;

	head = malloc(sizeof(llist));
	if(head == NULL)
		return NULL;

	head->next = NULL;

	return head;
}

void llist_insert(llist *head, void *data, int mode)
{
	llist *p = head;
	llist *new = NULL;

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
			while(p->next != NULL)// p != NULL
				p = p->next;
			p->next = new;
			break;
		default :
			printf("Insert Mode Is Error!\n");
			return ;
	}
}

void llist_display(llist *head)
{
	llist *p = head->next;//第一个有效节点
	for(p = head->next; p != NULL; p = p->next)
		printf("%d	%s	%d\n", p->id, p->name, p->math);
}

void llist_destroy(llist *head)
{
	llist *back = head;
	llist *p = head->next;

	while(p != NULL)
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

llist* llist_find(llist *head, void *find_data)
{
	llist *back = head;
	llist *p = head->next;

	while(p != NULL)
	{
		if(p->id == *(int *)find_data || 
				!strcmp(p->name, find_data))
		{
			printf("FInd It!\n");
			printf("===%d	%s	%d\n", p->id, p->name, p->math);
			return back;
		}
		back = p;
		p = p->next;
	}
	printf("Not Find It!\n");
	return NULL;
}














