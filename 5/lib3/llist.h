#ifndef __LLIST_H
#define __LLIST_H

#define HEADINSERT 0
#define TAILINSERT 1

typedef void (*list_op)(const void *);
// typedef void (*)(const void *) list_op;
typedef int (*list_cmp)(const void *, const void *);

typedef void LLIST;

LLIST *list_create(int );

int list_insert(LLIST *, const void *, int );

int list_display(LLIST *, list_op );

void list_destroy(LLIST *);

void *list_find(LLIST *, const void *, list_cmp);

int list_delete(LLIST *, const void *, list_cmp);

int list_fetch(LLIST *, const void *, list_cmp, void *);

#endif








