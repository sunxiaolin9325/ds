#ifndef __HANOI_H
#define __HANOI_H

#define STACK_LEN 20

#include <stdio.h>
#include <unistd.h>

typedef struct hanoi
{
	int stack[STACK_LEN];
	int stack_top;
} HANOI;

void hanoi_display(HANOI *);
void hanoi_play(HANOI *ptr, int src, int dest, int tmp, int num);
void move(HANOI *ptr, int src, int dest);







#endif
