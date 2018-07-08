#ifndef __JOSEPH_H
#define __JOSEPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int id;
	struct node *next;
}joseph;

joseph *joseph_create(int peo_num);

void joseph_display(joseph *l);

int joseph_play(joseph *l, int peo_num, int kill_num);

#endif





