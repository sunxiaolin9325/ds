#include <stdio.h>

typedef struct stu
{
	int id;
	char name[15];
	char a[0];
} STU;

int main(void)
{
	STU s;

	printf("%p\n", s.a);






	return 0;
}
