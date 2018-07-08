#ifndef __STACK_H
#define __STACK_H

#define STACK_LEN 50
#define DATA_LEN 20

static int stack[STACK_LEN];
static int stack_top;

#include <stdio.h>
#include <string.h>

void stack_push(int push_data);
int is_full();
int stack_pop();
int is_empty();
void stack_traverse();











#endif
