#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

LLIST *list_create(int size)
{
	LLIST *handle = NULL;
	handle = malloc(sizeof(LLIST));
	if(handle == NULL)
		return NULL;
	handle->size = size;
	handle->head.next = &handle->head;
	handle->head.prev = &handle->head;

	return handle;
}

int list_insert(LLIST *ptr, const void *data, int mode)
{
	struct list_node *newnode = NULL;

	newnode = malloc(sizeof(struct list_node));
	if(newnode == NULL)
		return -1;
	newnode->data = malloc(ptr->size);
	if(newnode->data == NULL)
	{
		free(newnode);
		return -2;
	}

	memcpy(newnode->data, data, ptr->size);
	switch(mode)
	{
		case 0 : 
			newnode->next = ptr->head.next;
			newnode->prev = &ptr->head;
			break;
		case 1 :
			newnode->prev = ptr->head.prev;
			newnode->next = &ptr->head;
			break;
		default:
			printf("Insert Mode Is Error!\n");
			//	free();
			return -3;
	}
	newnode->next->prev = newnode;
	newnode->prev->next = newnode;
}

int list_display(LLIST *ptr, list_op op)
{
	struct list_node *cur = NULL;

	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
		op(cur->data);
}

void list_destroy(LLIST *ptr)
{
	struct list_node *cur = NULL;
	struct list_node *next = NULL;

	for(cur = ptr->head.next; cur != &ptr->head; cur = next)
	{
		next = cur->next;
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		free(cur->data);
		free(cur);
	}
	free(ptr);
}

struct list_node *_find(LLIST *ptr, const void *data, list_cmp cmp)
{
	struct list_node *cur = NULL;

	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
		if(cmp(data, cur->data) == 0)
			break;
	return cur;
}

void *list_find(LLIST *ptr, const void *data, list_cmp cmp)
{
	return _find(ptr, data, cmp)->data;
}

int list_delete(LLIST *ptr, const void *data, list_cmp cmp)
{
	struct list_node *node = NULL;

	node = _find(ptr, data, cmp);
	if(node->data == NULL)
		return -1;
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free(node->data);
	free(node);
}

int list_fetch(LLIST *ptr, const void *data, list_cmp cmp, void *save)
{
	struct list_node *node = NULL;

	node = _find(ptr, data, cmp);
	if(node->data == NULL)
		return -1;
	memcpy(save, node->data, ptr->size);
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free(node->data);
	free(node);
}








