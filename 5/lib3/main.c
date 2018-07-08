#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

struct stu
{
	int id;
	char name[20];
	int math;
};

void print(const void *data)
{
	const struct stu *p = data;

	printf("%d	%s	%d\n", p->id, p->name, p->math);
}

int id_cmp(const void *key, const void *data)
{
	const int *k = key;
	const struct stu *p = data;

	return (*k - p->id);
}

int name_cmp(const void *key, const void *data)
{
	const char *k = key;
	const struct stu *p = data;

	return strcmp(k, p->name);
}

int main(void)
{
	LLIST *handle = NULL;	//指向头节点
	struct stu s, *datap, save;
	int i;
	int find_id = 100;
	char *find_name = "stu4";

	handle = list_create(sizeof(struct stu)); 
	//创建头节点
	
	if(handle == NULL)
		return -1;
	
	for(i = 0; i < 5; i++)
	{
		s.id = 100 + i;
		sprintf(s.name, "stu%d", i);
		s.math = 100 - i;
		//list_insert(handle, &s, HEADINSERT);
		list_insert(handle, &s, TAILINSERT);
		//插入节点
	}

	list_display(handle, print);//遍历链表
#if 0
	list_delete(handle, find_name, name_cmp);
#else
	list_fetch(handle, find_name, name_cmp, &save);
	
	printf("................\n");
	
	print(&save);

	printf("................\n");

#endif
	printf("=======================\n");
	
	list_display(handle, print);//遍历链表

/*
	printf("=======================\n");
	datap = list_find(handle, &find_id, id_cmp);
	if(datap == NULL)
		printf("Not Find It!\n");
	else
		print(datap);
	printf("=======================\n");
*/
	list_destroy(handle);		//销毁链表

	return 0;
}








