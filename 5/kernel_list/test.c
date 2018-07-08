#include <stdio.h>

struct list_node
{
	struct list_node *prev;
	struct list_node *next;
};

struct stu
{
	int id;
	char name[20];
	int math;
	struct list_node node;
};


int main(void)
{
	struct stu s;

	printf("&s.id = %p\n", &s.id);
	printf("s.name = %p\n", s.name);
	printf("&s.math = %p\n", &s.math);
	printf("&s.node = %p\n", &s.node);

printf("%d\n",(size_t)&((struct stu *)0)->node);

	return 0;
}












