#include "joseph.h"

joseph *joseph_create(int peo_num)
{
	joseph *l, *p, *new;
	int i = 1;

	l = malloc(sizeof(joseph));
	l->id = i++;
	l->next = l;
	p = l;
	
	while(--peo_num)
	{
		new = malloc(sizeof(joseph));
		new->id = i++;
		new->next = p->next;
		p->next = new;
		p = new;
	}

	return l;
}

void joseph_display(joseph *l)
{
	joseph *p = NULL;

	for(p = l; p->next != l; p = p->next)
		printf("%d ", p->id);
	printf("%d\n", p->id);
}

int joseph_play(joseph *l, int peo_num, int kill_num)
{
	joseph *back = l;	//要删除的前一个节点
	joseph *p;			//要删除的节点
	int kn = kill_num - 1;
	int alive = 0;

	while(--peo_num)
	{
		while(--kn)
			back = back->next;
		p = back->next;
		back->next = p->next;
		printf("%d ", p->id);
		free(p);
		back = back->next;
		kn = kill_num - 1;
	}
	
	alive = back->id;
	free(back);
	return alive;
}









