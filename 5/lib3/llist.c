#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

struct list_node			//可变长的结构体
{
	struct list_node *prev;
	struct list_node *next;
	char data[0];
};

struct list_head
{
	struct list_node head;
	int size;
};

LLIST *list_create(int size)
{
	//LLIST *handle = NULL;
	struct list_head *handle = NULL;

	handle = malloc(sizeof(*handle));
	if(handle == NULL)
		return NULL;
	handle->size = size;
	handle->head.prev = &handle->head;
	handle->head.next = &handle->head;

	return handle;
}

int list_insert(LLIST *p, const void *data, int mode)
{
	struct list_head *ptr = p;
	struct list_node *newnode = NULL;

	newnode = malloc(sizeof(struct list_node) + ptr->size);
	if(newnode == NULL)
		return -1;
	memcpy(newnode->data, data, ptr->size);

	switch(mode)
	{
		case 0 :
			newnode->prev = &ptr->head;
			newnode->next = ptr->head.next;
			break;
		case 1 :
			newnode->prev = ptr->head.prev;
			newnode->next = &ptr->head;
			break;
		default:
			printf("Insert Mode Is Error!\n");
			// free();
			return -2;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
}

int list_display(LLIST *p, list_op op)
{
	struct list_head *ptr = p;
	struct list_node *cur = NULL;

	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
		op(cur->data);
}

void list_destroy(LLIST *p)
{
	struct list_head *ptr = p;
	struct list_node *cur = NULL;
	struct list_node *next = NULL;

	for(cur = ptr->head.next; cur != &ptr->head; cur = next)
	{
		next = cur->next;
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		free(cur);
	}
	free(ptr);
}

struct list_node *_find(LLIST *p, const void *data, list_cmp cmp)
{
	struct list_head *ptr = p;
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

int list_delete(LLIST *p, const void *data, list_cmp cmp)
{
	struct list_head *ptr = p;
	struct list_node *node = NULL;

	node = _find(ptr, data, cmp);
	if(node->data == NULL)
		return -1;
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free(node);
	return 0;
}

int list_fetch(LLIST *p, const void *data, list_cmp cmp, void *save)
{
	struct list_head *ptr = p;
	struct list_node *node = NULL;

	node = _find(ptr, data, cmp);
	if(node->data == NULL)
		return -1;
	memcpy(save, node->data, ptr->size);
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free(node);
	return 0;
}












