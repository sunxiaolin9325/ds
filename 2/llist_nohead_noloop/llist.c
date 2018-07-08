#include "llist.h"

llist *llist_create(int num)
{
	llist *l = NULL;
	llist *p = NULL;
	llist *new = NULL;
	int i = 0;

	l = malloc(sizeof(llist));
	l->id = 100 + i;
	sprintf(l->name, "stu%d", i);
	l->math = 100 - i;
	l->next = NULL;
	p = l;

	for(i += 1; i < num; i++)
	{
		new = malloc(sizeof(llist));
		new->id = 100 + i;
		sprintf(new->name, "stu%d", i);
		new->math = 100 - i;
		new->next = NULL;
		p->next = new;
		p = new;
	}

	return l;
}

void llist_display(llist *l)
{
	llist *p = l;

	for(p = l; p != NULL; p = p->next)
		printf("%d	%s	%d\n", p->id, p->name, p->math);
}

void llist_destroy(llist *l)
{
	llist *back = l;
	llist *p = l->next;

	while(p != NULL)
	{
		back->next = p->next;
		free(p);
		p = back->next;
	}
	free(back);
	back = NULL;
}

void llist_delete(llist **l, void *find_data)
{
	llist *back = *l;
	llist *p = NULL;

	p = llist_find(*l, find_data);
	if(p == NULL)//没有找到
	{
		printf("Delete It Is Failed!\n");
		return ;
	}
	if(p == *l)//删除节点就是第一个节点
	{
		*l = (*l)->next;
		free(p);
		return ;
	}
	//删除节点是其他节点
	while(back->next != p)
		back = back->next;
	back->next = p->next;
	free(p);
	p = NULL;
}

llist *llist_find(llist *l, void *find_data)
{
	llist *p = l;

	for(p = l; p != NULL; p = p->next)
	{
		if(p->id == *(int *)find_data || 
		  !strcmp(p->name, find_data))
		{
			printf("Find It!\n");
			printf("@@@%d	%s	%d\n", p->id, p->name, p->math);
			return p;
		}
	}
	printf("Not Find It!\n");
	return NULL;
}












