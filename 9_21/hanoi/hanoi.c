#include "hanoi.h" 

void hanoi_display(HANOI *ptr)
{
	int i, j;

	for (i=0; i<3; i++)
	{
		for (j=0; j<ptr[i].stack_top; j++)
		{
			printf("%d", ptr[i].stack[j]);
		}

		for (; j<10; j++)
		{
			printf("-");
		}
		printf("\n");
	}
}

void hanoi_play(HANOI *ptr, int src, int dest, int tmp, int num)
{
	printf("11111111111111111111\n");
	if (num == 1)
	{
		move(ptr, src, dest);
		return;
	}
	hanoi_play(ptr, src, tmp, dest, num - 1);
	move(ptr, src, dest);
	hanoi_play(ptr, tmp, dest, src, num - 1);
	printf("11111111111111111111\n");
}


void move(HANOI *ptr, int src, int dest)
{
	getchar();
	printf("22222222222222222222222\n");

	ptr[src].stack_top--;
	ptr[dest].stack[ptr[dest].stack_top] = ptr[src].stack[ptr[src].stack_top];
	ptr[dest].stack_top++;

	system("clear");
	hanoi_display(ptr);
	printf("222222222222222222222222222\n");
}











