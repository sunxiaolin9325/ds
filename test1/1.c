#include <stdio.h>

typedef struct Stu
{
	int id;
	char name[15];
	int score;
} STU;
int main(void)
{
	int i;
	STU s[3] = {{11, "qwe", 34},
				{22, "wer", 23},
				{33, "fra", 43}};
	STU t;

	for (i = 0; i < 3; i++)
	{
		printf("%d\t", s[i].id);
		printf("%s\t", s[i].name);
		printf("%d\n", s[i].score);
	}

	t = s[0];
	s[0] = s[1];
	s[1] = t;

	for (i = 0; i < 3; i++)
	{
		printf("%d\t", s[i].id);
		printf("%s\t", s[i].name);
		printf("%d\n", s[i].score);
	}

	return 0;
}
