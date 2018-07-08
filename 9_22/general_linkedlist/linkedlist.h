#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADINSERT 0
#define TALIINSERT 1

typedef struct Data_node
{
	void *data_ptr;
	struct Data_node *prev;
	struct Data_node *next;
} DATA_NODE;

typedef struct Head_node
{
	DATA_NODE head;
	int data_size;
} HEAD_NODE;


HEAD_NODE *linkedlist_create(int data_size);
int linkedlist_insert(HEAD_NODE *handle, void *data_ptr, int mode);
int linkedlist_traverse(HEAD_NODE *handle, void (*p)(const void *));
void linkedlist_destroy(HEAD_NODE *);
DATA_NODE *_find(HEAD_NODE *, const void *, int (*)(const void *, const void *));
void *linkedlist_find(HEAD_NODE *, const void *, int (*)(const void *, const			void *));
int linkedlist_delete(HEAD_NODE *, const void *,
		int (*)(const void *, const void *));
int linkedlist_fetch(HEAD_NODE *, const void *, int (*)(const void *, const void *), void *);


#endif
