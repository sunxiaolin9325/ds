#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

#include "list.h"

struct stu
{
	int id;
	char name[15];
	int score;
	struct list_head node;
};

/*
 * 打印一个结点到数据
 */
void print(struct stu *p)
{
	printf("%d %s %d\n", p->id, p->name, p->score);
}

int main(void)
{
	struct stu *s, *datap, save;
	struct list_head *pos;
	int i;
	int find_id = 1005;
	char *find_name = "stu1";

	LIST_HEAD(head);	//创建头结点

/*
 * 增加数据
 */
	for (i=0; i<5; i++)
	{
		s = malloc(sizeof(struct stu));
		s->id = 1001 + i;
		sprintf(s->name, "stu%d", 1 + i);
		s->score = 100 * (1 + i);
	//	list_add(&s->node, &head);	
		list_add_tail(&s->node, &head);	
	}

/*
 * 遍历打印数据
 */
	list_for_each(pos, &head)
	{
		datap = list_entry(pos, struct stu, node);
		print(datap);			
	}

/*
 * 删除一个结点
 */
	list_for_each(pos, &head)
	{
		datap = list_entry(pos, struct stu, node);
		if (strcmp(datap->name, find_name) == 0)
			break;
	}
	list_del(pos);		
	free(datap);

/*
 * 删除一个结点并读取数据
 */
	list_for_each(pos, &head)
	{
		datap = list_entry(pos, struct stu, node);
		if (datap->id == find_id)
			break;
	}

	list_del(pos);
	save = *datap;
	free(datap);
	print(&save);

/*
 * 销毁链表
 */
	list_for_each(pos, &head)
	{
		datap = list_entry(pos, struct stu, node);
		free(datap);
	}

	return 0;
}
