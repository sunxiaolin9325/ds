#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>

#define STACKSIZE 6

static int stack[STACKSIZE];
static int ind;

int stack_push(int data);

int stack_pop();

int isempty();

int isfull();

void stack_display();

#endif








