#ifndef __LIST_H
#define __LIST_H

#define HEADINSET 0
#define TAILINSET 1

typedef void (*list_opr)(const void *);
typedef int (*list_cmp)(const void *, const void *);

typedef struct data_node
{
	struct data_node *prev;	
	struct data_node *next;	
	char data[0];
} DATA_NODE;

typedef struct head_node
{
	struct data_node head;
	int size;
} HEAD_NODE;

HEAD_NODE *list_create(int );

int list_add(HEAD_NODE *, const void *, int );

int lsit_traverse(HEAD_NODE *, list_opr);

void lsit_destroy(HEAD_NODE *);

void *list_find(HEAD_NODE *, const void *, list_cmp);

int list_delete(HEAD_NODE *, const void *, list_cmp);

int list_fetch(HEAD_NODE *, const void *, list_cmp);






#endif

