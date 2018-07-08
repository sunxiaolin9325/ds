#include "llist.h"

int main(void)
{
	llist *head = NULL;//指向头节点
	llist data;			//数据
	int find_id = 100;
	char *find_name = "stu4";
	int i;

	head = llist_create();//创建头节点

	if(head == NULL)
		return -1;

	for(i = 0; i < 5; i++)
	{
		data.id = 100 + i;
		sprintf(data.name, "stu%d", i);
		data.math = 100 - i;
		llist_insert(head, &data, 1);//插入节点
		// 0头插法	1尾插法
	}
	
	llist_display(head);//遍历链表

#if 1
	llist_delete(head, find_name);//链表的删除
#else
	llist_find(head, find_name); //链表的查找
#endif
	
	llist_display(head);//遍历链表

	llist_destroy(head);//销毁链表

	return 0;
}














