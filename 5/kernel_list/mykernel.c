#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

struct stu
{
	int id;
	char name[20];
	int math;
	struct list_head node;
};

void print(const void *data)
{
	const struct stu *p = data;

	printf("%d	%s	%d\n", p->id, p->name, p->math);
}

int main(void)
{
	LIST_HEAD(handle);		//创建头节点
	struct stu *s, *datap;
	struct list_head *pos;
	int i;
	int find_id = 100;
	char *find_name = "stu4";

	for(i = 0; i < 5; i++)
	{
		s = malloc(sizeof(struct stu));
		s->id = 100 + i;
		sprintf(s->name, "stu%d", i);
		s->math = 100 - i;
		//list_add(&s->node, &handle);//插入数据节点
		list_add_tail(&s->node, &handle);//插入数据节点
	}

	list_for_each(pos, &handle)		//遍历链表
	{
		datap = list_entry(pos, struct stu, node);
		print(datap);
	}

	list_for_each(pos, &handle)		//删除节点
	{
		datap = list_entry(pos, struct stu ,node);
		if(strcmp(find_name, datap->name) == 0)
		{
			list_del(pos);
			free(datap);
			break;
		}
	}

	printf("======================\n");

	list_for_each(pos, &handle)		//遍历链表
	{
		datap = list_entry(pos, struct stu, node);
		print(datap);
	}

	list_for_each(pos, &handle)		//销毁链表
	{
		datap = list_entry(pos, struct stu, node);
		free(datap);
	}

	return 0;
}











