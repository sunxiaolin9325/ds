/*malloc*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *p;
	int i;

	p = malloc(sizeof(int));
	
	for(i = 0; i < 4; i++)
		*(p + i) = 100 + i;
	
	for(i = 0; i < 4; i++)
		printf("*(p + %d) = %d\n", i, *(p + i));

	free(p);

	return 0;
}









