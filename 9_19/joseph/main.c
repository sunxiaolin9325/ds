#include "func.h"

int main(void)
{
	int peo_num, kill_digit, alive;

	printf("Input the number of people: ");
	scanf("%d", &peo_num);
	NODE *first = joseph_create(peo_num);

	joseph_traverse(first);
	printf("=====================\n");

	printf("Input the digit of kill: ");
	scanf("%d", &kill_digit);

	alive = joseph_play(first, peo_num, kill_digit);
	printf("alive id %d\n", alive);

//	joseph_destroy(first);

	return 0;
}
