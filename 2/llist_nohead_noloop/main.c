#include "llist.h"

#define NUM 5

int main(void)
{
	llist *l = NULL;
	int find_id = 100;
	char *find_name = "stu4";

	l = llist_create(NUM);	//	创建无头链表
	
	llist_display(l);		//	遍历链表
#if 1
	llist_delete(&l, find_name);
#else
	llist_find(l, find_name);
#endif

	printf("====================\n");
	
	llist_display(l);		//	遍历链表

	llist_destroy(l);		//	销毁链表

	return 0;
}











