/*malloc*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;

	p = malloc(sizeof(int));

	*p = 100;

	printf("*p = %d\n", *p);

	free(p);
	
	*p = 200;

	printf("*p = %d\n", *p);

	return 0;
}









