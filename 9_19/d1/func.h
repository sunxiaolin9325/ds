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
	int score;
	struct Stu *next;
} STU;

void llist_traverse(STU *);










#endif

