#ifndef __FUNC_H
#define __FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 15
#define HEADINSERT 0
#define TAILINSERT 1

typedef struct Node
{
	int id;
	char name[BUFSIZE];
	int score;
	struct Node *prev;
	struct Node *next;
} NODE;

NODE *llist_create();
void llist_insert(NODE *, NODE *, int);
void llist_traverse(NODE *);
void llist_destroy(NODE *);
NODE *llist_find(NODE *, void *);
void llist_delete(NODE *, void *);










#endif
