#include "linkedlist.h"

HEAD_NODE *linkedlist_create(int data_size)
{
	HEAD_NODE *handle = NULL;

	handle = malloc(sizeof(HEAD_NODE));
	if (handle == NULL)
		return NULL;

	handle->head.data_ptr = NULL;
	handle->head.prev = &handle->head;
	handle->head.next = &handle->head;
	handle->data_size = data_size;

	return handle;
}

int linkedlist_insert(HEAD_NODE *handle, void *data_ptr, int mode)
{
	HEAD_NODE *ptr = handle;
	DATA_NODE *new = NULL;

	new = malloc(sizeof(DATA_NODE));
	if (new == NULL)
		return -1;

	new->data_ptr = malloc(ptr->data_size);
	if (new->data_ptr == NULL)
		return -2;

	memcpy(new->data_ptr, data_ptr, ptr->data_size);
	switch (mode)
	{
		case 0:
			new->next = ptr->head.next;
			new->prev = &ptr->head;
			break;
		case 1:
			new->next = &ptr->head;
			new->prev = ptr->head.prev;
			break;
		default:
			printf("Mode error\n");
			//free();
			return -3;
	}
	new->next->prev = new;
	new->prev->next = new;
	return 0;
}

int linkedlist_traverse(HEAD_NODE *handle, void (*p)(const void *))
{
	HEAD_NODE *ptr = handle;
	DATA_NODE *cur = ptr->head.next; 
	if (cur == &ptr->head)
	{
		printf("linkedlist is empty.\n");
		return -1;
	}
	
	while (cur != &ptr->head)
	{
		p(cur->data_ptr);
		cur = cur->next;
	}
	return 0;
}

void linkedlist_destroy(HEAD_NODE *ptr)
{
	DATA_NODE *cur = ptr->head.next;
	DATA_NODE *tmp = NULL;

	while (cur != &ptr->head)
	{
		tmp = cur;
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		free(cur);
		cur = tmp->next;
	}
	free(ptr);
}

DATA_NODE *_find(HEAD_NODE *handle, const void *data, 
		int (*p)(const void *, const void *))
{
	HEAD_NODE *ptr = handle;
	DATA_NODE *cur = ptr->head.next;

	while (cur != &ptr->head)
	{
		if (p(cur->data_ptr, data) == 0)
			break;
		cur = cur->next;
	}
	return cur;
}

void *linkedlist_find(HEAD_NODE *handle, const void *data, 
		int (*p)(const void *, const void *))
{
	return _find(handle, data, p)->data_ptr;
}

int linkedlist_delete(HEAD_NODE *handle, const void *data,
		int (*p)(const void *, const void *))
{
	DATA_NODE *cur = _find(handle, data, p);

	if (cur == &handle->head)
		return -1;
	
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	free(cur->data_ptr);
	free(cur);
	return 0;
}

int linkedlist_fetch(HEAD_NODE *handle, const void *data, int (*p)(const void *, const void *), void *save)
{
	DATA_NODE *cur = _find(handle, data, p);

	if (cur == &handle->head)
		return -1;
	
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	memcpy(save, cur->data_ptr, handle->data_size);
	free(cur->data_ptr);
	free(cur);
	return 0;

}


