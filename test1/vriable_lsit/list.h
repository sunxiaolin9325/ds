#ifndef __LSIT_H
#define __LSIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADINSERT 0 
#define TAILINSERT 1 

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
	DATA_NODE head;
	int size;
} HEAD_NODE;

HEAD_NODE *list_create(int);

int list_add(HEAD_NODE *, const void *, int);

int list_traverse(HEAD_NODE *, list_opr);

void list_destroy(HEAD_NODE *);

void *list_find(HEAD_NODE *, const void *, list_cmp);

int list_delete(HEAD_NODE *, const void *, list_cmp);

int list_fetch(HEAD_NODE *, const void *, list_cmp, void *);











#endif
