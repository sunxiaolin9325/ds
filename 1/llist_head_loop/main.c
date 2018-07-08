#include "llist.h"

int main(void)
{
	llist *head = NULL;
	llist data;
	int i;
	int find_id = 100;
	char *find_name = "stu4";

	head = llist_create();//创建头节点
	if(head == NULL)
		return -1;
	
	for(i = 0; i < 5; i++)
	{
		data.id = 100 + i;
		sprintf(data.name, "stu%d", i);
		data.math = 100 - i;
		llist_insert(head, &data, 1);//插入节点
		//0	头插法	1	尾插法
	}

	llist_display(head);//遍历链表
#if 0
	llist_delete(head, find_name);//删除节点
#else
	llist_find(head, &find_id);//查找节点
#endif
	
	llist_display(head);//遍历链表

	llist_destroy(head);//销毁链表

	return 0;
}












