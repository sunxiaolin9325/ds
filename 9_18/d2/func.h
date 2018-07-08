#ifndef __FUNC_H
#define __FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADINSERT 0
#define TAILINSERT 1
#define BUFSIZE 15

typedef struct Stu
{
	int id;
	char name[BUFSIZE];
	float score;
	struct Stu *next;
} STU;

STU *linkedlist_create();
void linkedlist_insert(STU *, void *, int);
void linkedlist_traverse(STU *);
void linkedlist_destroy(STU *);
void linkedlist_delete(STU *, void *);
STU *linkedlist_find(STU *, void *);





#endif
