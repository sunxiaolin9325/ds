#include <stdio.h>

int main(void)
{
	int a = 1;
	int *p = &a;// p = NULL;

	printf("a = %d\n", a);

	*p = 100;//段错误

	printf("*p = %d\n", *p);

	printf("a = %d\n", a);
	
	return 0;
}






