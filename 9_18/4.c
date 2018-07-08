#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
	char *p;
	int *q;

	q = (char *)malloc(sizeof(int));
	printf("%p\n", q);
	q++;
	printf("%p\n", q);
	q++;
	printf("%p\n", q);
	q++;
	printf("%p\n", q);
	q++;
	printf("%p\n", q);


	return 0;
}
