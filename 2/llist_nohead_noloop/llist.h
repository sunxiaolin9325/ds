#ifndef __LLIST_H
#define __LLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu
{
	int id;
	char name[20];
	int math;
	struct stu *next;
}llist;

llist *llist_create(int num);

void llist_display(llist *l);

void llist_destroy(llist *l);

void llist_delete(llist **l, void *find_data);

llist *llist_find(llist *l, void *find_data);

#endif








