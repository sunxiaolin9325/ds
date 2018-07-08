#include <stdio.h>

struct node
{
	struct node *prev;
	struct node *next;
};

struct stu
{
	int id;
	char name[15];
	int score;
	struct node node;
};


int main(void)
{
	struct stu s;

	struct node *ptr = &s.node;

	printf("id = %p\n", &s.id);
	printf("name = %p\n", s.name);
	printf("score = %p\n", &s.score);
	printf("node = %p\n", &s.node);
	printf("prev = %p\n", s.node.prev);
	printf("next = %p\n", s.node.next);

	printf("node = %ld\n", (size_t)&((struct stu *)0)->node);
	printf("node = %p\n", &((struct stu *)0)->node);
//	printf("node = %p\n", ((struct stu *)0)->node);
	printf("%p\n", (struct stu *)(size_t)&((struct stu *)0)->node);
	printf("node = %p\n", &s.node);

	const typeof( ((struct stu *)0)->node) *_mptr = ptr;
	//const typeof(s.node) *__mptr = ptr;
	printf("%p\n", (struct stu *)( (char *)_mptr - (size_t)&((struct stu *)0)->node));
	
	const typeof( ((struct stu *)10)->node) *__mptr = ptr;
	printf("%p\n", (struct stu *)( (char *)__mptr - (size_t)&((struct stu *)0)->node));
	//printf("__mptr = %p\n", __mptr);



	return 0;
}
