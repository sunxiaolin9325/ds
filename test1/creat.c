#include <stdio.h>

typedef struct Stu
{
	int id;
	char name[15];
	int score[5];
	int total;
	int ranking;
} STU, *PSTU;

int main(void)
{
	STU s[3] = {{1214210101, "baojianfeng", {60, 70, 70, 80, 80}, 360, 2},
				{1214210102, "baorui",	  {60, 70, 80, 80, 80}, 370, 1},
				{1214210103, "caozhifeng",  {60, 60, 70, 80, 80}, 350, 3}};
	FILE *fp = NULL;

	fp = fopen("data", "w");
	if (fp == NULL)
	{
		perror("fopen()");
		return -1;
	}

	fwrite(s, sizeof(STU), 3, fp);

	fclose(fp);
	fp = NULL;

	return 0;
}
