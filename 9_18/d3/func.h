#ifndef __FUNC_H
#define __FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 15
#define HEADINSERT 0
#define TAILINSERT 1

typedef struct Stu
{
	int id;
	char name[BUFSIZE];
	int score;
	struct Stu *next;
} STU;

STU *llist_create();
void llist_insert(STU *, STU *, int);
void llist_traverse(STU *);
STU *llist_find(STU *, void *);
void llist_delete(STU *, void *);
void llist_destroy(STU *);











#endif
