#include "list.h"

HEAD_NODE *list_create(int size)
{
	HEAD_NODE *handle = NULL;

	handle = malloc(sizeof(HEAD_NODE));
	if (handle == NULL)
		return NULL;

	handle->head.prev = &handle->head;
	handle->head.next = &handle->head;
	handle->size = size;
	return handle;
}

int list_add(HEAD_NODE *handle, const void *data, int mode)
{
	DATA_NODE *new = NULL;

	new = malloc(sizeof(handle->head) + handle->size);
	if (new == NULL)
		return -1;

	memcpy(new->data, data, handle->size);	
	switch (mode)
	{
		case 0:
			new->next = handle->head.next;
			new->prev = &handle->head;
			break;
		case 1:
			new->next = &handle->head;
			new->prev = handle->head.prev;
			break;	
		default:
			printf("Insert mode error\n");
			break;
	}
	new->next->prev = new;
	new->prev->next = new;
	return 0;
}

int list_traverse(HEAD_NODE *handle, list_opr opr)
{
	HEAD_NODE *ptr = handle;

	DATA_NODE *cur = ptr->head.next;
	while (cur != &ptr->head)
	{
		opr(cur->data);
		cur = cur->next;
	}
}

void list_destroy(HEAD_NODE *handle)
{
	HEAD_NODE *ptr = handle;

	DATA_NODE *cur = ptr->head.next;
	while (cur != &ptr->head)
	{
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		free(cur);
		cur = cur->next;
	}
	free(ptr);
}

DATA_NODE *_find(HEAD_NODE *handle, const void *data, list_cmp cmp)
{
	HEAD_NODE *ptr = handle;

	DATA_NODE *cur = ptr->head.next;
	while (cur != &ptr->head)
	{
		if (cmp(cur->data, data) == 0)
			break;
		cur = cur->next;
	}
	return cur;
}

void *list_find(HEAD_NODE *handle, const void *data, list_cmp cmp)
{
	return _find(handle, data, cmp)->data;
}

int list_delete(HEAD_NODE *handle, const void *data, list_cmp cmp)
{
	HEAD_NODE *ptr = handle;
	DATA_NODE *cur = _find(handle, data, cmp);
	
	if (cur == &ptr->head)
		return -1;

	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	free(cur);
}

int list_fetch(HEAD_NODE *handle, const void *data, 
							list_cmp cmp, void *save)
{
	HEAD_NODE *ptr = handle;
	DATA_NODE *cur = _find(handle, data, cmp);
	
	if (cur == &ptr->head)
		return -1;

	memcpy(save, cur->data, ptr->size);
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	free(cur);
}


