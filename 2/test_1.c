#include <stdio.h>

void change(int **p, int *b)
{
	*p = b;
}

int main(void)
{
	int a = 100;
	int b = 200;
	int *p = &a;

	printf("*p = %d\n", *p);

	change(&p, &b);

	printf("*p = %d\n", *p);

	return 0;
}












