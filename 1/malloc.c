/*malloc*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;

	p = malloc(sizeof(int));
	// malloc	开辟内存空间

	printf("p = %p\n", p);

	*p = 100;

	printf("*p = %d\n", *p);

	free(p);
	
	p = NULL;

	return 0;
}









