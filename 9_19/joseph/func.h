#ifndef __FUNC_H
#define __FUNC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int id;
	struct Node *next;
} NODE;

NODE *joseph_create(int);
void joseph_traverse(NODE *);
int joseph_play(NODE *, int, int);
//void joseph_destroy(NODE *);


#endif
