#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;
	int i;

	p = malloc(sizeof(int));
	printf("%p\n", p);
	p++;
	printf("%p\n", p);
		
	for (i = 0; i < 4; i++)
	{
		*(p + i) = 100 + i;
		printf("%d\n", *(p + i));
	printf("%p\n", p + i);
	}


	return 0;
}
