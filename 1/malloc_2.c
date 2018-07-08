/*malloc
	malloc
		开辟的堆空间的内存
	如果执行的时候出现
	已放弃或者core dumped
	说明是段错误(编译器不检查段错误)
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;

	p = malloc(sizeof(int));

	*p = 100;

	printf("*p = %d\n", *p);

	free(p);
	printf("=============hello world!\n");
	free(p);

	return 0;
}









