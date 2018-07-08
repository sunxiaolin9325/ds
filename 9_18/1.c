#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;
	p = malloc(sizeof(int));
	printf("%p\n", p);
	*p = 200;
	printf("%d\n", *p);
	free(p);
	printf("===========");
	free(p);
	printf("%p\n", p);
	printf("%d\n", *p);
	*p = 300;
	printf("%d\n", *p);
	free(p);
	p = NULL;
	printf("%p\n", p);




	return 0;
}
