#include <stdio.h>
#include <string.h>
#include "list.h"

#define NAMESIZE 15

typedef struct stu
{
	int id;
	char name[NAMESIZE];
	int score;
} STU;

void print(const void *data)
{
	const STU *p = data;
	printf("%d %s %d\n", p->id, p->name, p->score);
}

int id_cmp(const void *data, const void *find_id)
{
	const STU *p = data;
	const int id = *(const int *)find_id;

	return (p->id - id);
}

int name_cmp(const void *data, const void *find_name)
{
	const STU *p = data;
	const char *q = find_name;

	return strcmp(p->name, q);
}

int main(void)
{
	HEAD_NODE *handle = NULL;
	STU s, save;
	STU *data_ptr;
	int i;
	int find_id = 1001;
	char *find_name = "stu5";

	handle = list_create(sizeof(STU)); 

	for (i=0; i<5; i++)
	{
		s.id = 1001 + i;
		sprintf(s.name, "stu%d", i + 1);
		s.score = 60 + 10 * i;
		list_add(handle, &s, 1);
	}

	list_traverse(handle, print);
/*
	data_ptr = list_find(handle, find_name, name_cmp);
	if (data_ptr == (STU *)handle->head.data)
		printf("Not find\n");
	else
		print(data_ptr);
*/
//	list_delete(handle, find_name, name_cmp);
	list_fetch(handle, find_name, name_cmp, &save);
	print(&save);
	
	printf("===================\n");	
	list_traverse(handle, print);
	
	list_destroy(handle);

	return 0;
}
