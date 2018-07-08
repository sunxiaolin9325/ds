#include <stdio.h>

#define N 10

int main(void)
{
	int i, num = 0, n = 10;
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (i = 0; i < N; i++)
	{
		if (a[i] != 0)
		{
			num += 1;
			if (num % 3 == 0)
			{
				num = 0;
				a[i] = 0;
				n--;
			}
		}
		if (i == 9)
			i = -1;
		if (n == 1)
			break;
	}
	
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	return 0;
}
