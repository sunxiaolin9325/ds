#include <stdio.h>

int main(void)
{
	int a = 10;

	a = ({
		int j = 0;
		j = 1;
	});

	printf("a = %d\n", a);

	return 0;
}
