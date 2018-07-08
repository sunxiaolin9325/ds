#include "joseph.h"

int main(void)
{
	joseph *l;
	int peo_num = 0;	//	人数
	int kill_num = 0;	//	数的数字
	int alive = 0;		//	接收活下来的id

	printf("Please Insert People Number : ");
	scanf("%d", &peo_num);
	l = joseph_create(peo_num);	//创建joseph环

	joseph_display(l);			//遍历joseph环

	printf("==============================\n");
	
	printf("Please Insert Kill Number : ");
	scanf("%d", &kill_num);

	alive = joseph_play(l, peo_num, kill_num);
	//	开始游戏
	
	printf("\n alive : %d\n", alive);

	return 0;
}










