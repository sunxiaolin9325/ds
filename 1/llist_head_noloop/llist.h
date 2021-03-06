#ifndef __LLIST_H
#define __LLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 20
#define HEADINSERT 0
#define TAILINSERT 1

typedef struct stu
{
	int id;
	char name[NAMESIZE];
	int math;
	struct stu *next;
}llist;

llist *llist_create();

void llist_insert(llist *head, void *data, int mode);

void llist_display(llist *head);

void llist_destroy(llist *head);

void llist_delete(llist *head, void *find_data);

llist* llist_find(llist *head, void *find_data);

#endif








