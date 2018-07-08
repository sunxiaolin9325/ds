#include <stdio.h>

void change(int *a, int num)
{
	*a = num;
}

int main(void)
{
	int a = 100;

	printf("a = %d\n", a);

	change(&a, 200);

	printf("a = %d\n", a);

	return 0;
}












