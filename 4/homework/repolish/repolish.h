#ifndef __REPOLISH_H
#define __REPOLISH_H

#define STACKSIZE 6

static int stack[STACKSIZE];
static int ind;

int stack_push(int data);

int stack_pop();

int isfull();

int isempty();

void stack_display();

#endif








