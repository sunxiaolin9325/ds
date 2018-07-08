#ifndef __FUNC_H
#define __FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 15

typedef struct Stu
{
	int id;
	char name[BUFSIZE];
	float score;
	struct Stu *next;
} STU, *PSTU;

PSTU headNode_create();
void linkedList_insert(PSTU, void *, int);
void linkedList_traverse(PSTU);
void linkedList_destroy(PSTU);
void linkedList_delete(PSTU, void *);
PSTU linkedList_find(PSTU, void *);

#endif
