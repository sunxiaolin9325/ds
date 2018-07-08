#include "func.h"

NODE *joseph_create(int peo_num)
{
	int i = 1;
	NODE *new = NULL;
	NODE *first = malloc(sizeof(NODE));
	NODE *p = first;
	p->id = i;
	p->next = p;

	for (i = 2; i <= peo_num; i++)
	{
		new = malloc(sizeof(NODE));	
		new->id = i;
		new->next = p->next;
		p->next = new;
		p = new;
	}
	return first;
}

void joseph_traverse(NODE *first)
{
	NODE *p = first;

	do
	{
		printf("%d ", p->id);
		p = p->next;
	} while (p != first);
	printf("\n");
}

int joseph_play(NODE *first, int peo_num, int kill_digit)
{
	NODE *p = first;
	NODE *q = p->next;
	int kd, alive;

	while (--peo_num)
	{
		kd = kill_digit - 1;
		while (--kd)
		p = p->next;
		q = p->next;
		p->next = q->next;
		printf("%d ", q->id);
		free(q);
		p = p->next;
	} 
	printf("\n");
	alive = p->id;
	free(p);
	p = NULL;

	return alive;
}

/*	不能使用
void joseph_destroy(NODE *first)
{
	NODE *p = first;
	NODE *q = p->next;

	while (p->next != first)
	{
		p->next = q->next;
		free(q);
		q = p->next;
		printf("=====================\n");
	}
	free(first);
	p = NULL;
}
*/
