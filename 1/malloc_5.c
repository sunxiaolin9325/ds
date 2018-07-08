#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;
	int *q = NULL;
	int i = 0;

	p = malloc(sizeof(int) * 4);

	q = p;

	for(i = 0; i < 4; i++)
	{
		*p = 100 + i;
		printf("*p = %d\n", *p);
		p++;
	}

	free(q);

	return 0;
}







