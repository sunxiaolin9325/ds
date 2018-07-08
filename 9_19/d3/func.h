#ifndef __FUNC_H
#define __FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5
int flag;

typedef struct Stu
{
	int id;
	char name[15];
	int score;
	struct Stu *next;
} STU;

STU *llist_create(int );
void llist_traverse(STU *);
void llist_destroy(STU *);
STU *llist_find(STU *, void *);
void llist_delete(STU **, void *);









#endif

