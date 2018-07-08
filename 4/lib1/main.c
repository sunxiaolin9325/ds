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

	//创建头节点
	handle = list_create(sizeof(struct stu));
	
	if(handle == NULL)
		return -1;
	
	for(i = 0; i < 5; i++)
	{
		s.id = 100 + i;
		sprintf(s.name, "stu%d", i);
		s.math = 100 - i;
		//插入节点
		list_insert(handle, &s, HEADINSERT);
	}

	list_display(handle, print);//遍历链表

#if 0
	list_delete(handle, find_name, name_cmp);
	printf("=====================\n");
#else
	printf("\n\n\n");
	list_fetch(handle, "stu2", name_cmp, &save);
	print(&save);
	printf("\n\n\n");
#endif

	list_display(handle, print);//遍历链表

#if 0
	printf("====================\n");
	datap = list_find(handle, find_name, name_cmp);
	if(datap == NULL)
		printf("Not FInd It!\n");
	else
		print(datap);
	printf("====================\n");
#endif

	list_destroy(handle);		//销毁链表

	return 0;
}
/*
	find
	delete
	fetch
*/











