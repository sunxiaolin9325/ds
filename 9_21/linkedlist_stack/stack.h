#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include "llist.h"

llist *stack_create();

void stack_push(llist *, int *);

int stack_pop(llist *);

int isempty(llist *);

void stack_display(llist *);

#endif








