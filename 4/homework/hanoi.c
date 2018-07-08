#include <stdio.h>

struct
{
	int hanoi[7];
	int ind;
}hanoi_arr[3] = {
	{{7,6,5,4,3,2,1}, 7}, 
	{},
	{},
};

void display()
{
	int i, j;

	system("clear");
	for(i = 0; i < 3; i++)//三根柱子
	{
		for(j = 0; j < hanoi_arr[i].ind; j++)
			//打印柱子中的铁饼
		{
			printf("%d", hanoi_arr[i].hanoi[j]);
		}
	/*	for(; j < 10; j++)
		{
			printf("-");
		}
	*/	printf("\n");
	}
	getchar();
}

void move(int src, int dest)
{
	int tmp;

	hanoi_arr[src].ind--;
	tmp = hanoi_arr[src].hanoi[hanoi_arr[src].ind];
	hanoi_arr[dest].hanoi[hanoi_arr[dest].ind] = tmp;
	hanoi_arr[dest].ind++;

	display();
}

void play(int src, int dest, int tmp, int num)
{
	if(num == 1)
	{
		move(src, dest);
		return ;
	}
	play(src, tmp, dest, num - 1);
	move(src, dest);
	play(tmp, dest, src, num - 1);
}

int main(void)
{
	display();

	play(0, 1, 2, 7);

	return 0;
}










