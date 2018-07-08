#include <stdio.h>

int main(void)
{
	int *p;// p = NULL;

	*p = 100;//段错误

	printf("*p = %d\n", *p);

	return 0;
}






