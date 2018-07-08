#include "linkedlist.h"
#include <stdio.h>

#define NAMESIZE 15

typedef struct Stu
{
	int id;
	char name[NAMESIZE];
	int score;
} STU;

void print(const void *data)
{
	const STU *p = data;

	printf("%d\t%s\t%d\n", p->id, p->name, p->score);
}

int id_cmp(const void *data, const void *find_id)
{
	STU *p = (STU *)data;
	int *q = (int *)find_id;

	return (p->id - *q);
}

int name_cmp(const void *data, const void *find_name)
{
	STU *p = (STU *)data;

	return strcmp(p->name, find_name);
}

int main(void)
{
	HEAD_NODE *handle = NULL;
	STU stu, save;
	STU *data_ptr = NULL;
	int i;
	int find_id = 1001;
	char *find_name = "stu5";

	handle = linkedlist_create(sizeof(STU));
	if (handle == NULL)
		return -1;

	for (i=0; i<5; i++)
	{
		stu.id = 1001 + i;
		sprintf(stu.name, "stu%d", i + 1);
		stu.score = 100 * (i + 1);
		linkedlist_insert(handle, &stu, 1);
	}

	linkedlist_traverse(handle, print);
	printf("===============\n");

#if 0

#if 0
	data_ptr = linkedlist_find(handle, &find_id, id_cmp);
#else
	data_ptr = linkedlist_find(handle, find_name, name_cmp);
#endif

	//if (data_ptr = NULL)
	if (data_ptr == NULL)
		printf("Not find.\n");
	else 
		print(data_ptr);
#else

#if 0
	linkedlist_delete(handle, &find_id, id_cmp);
#else
//	linkedlist_delete(handle, find_name, name_cmp);
#endif

//	linkedlist_traverse(handle, print);
	printf("===============\n");

#endif

#if 1
	linkedlist_fetch(handle, find_name, name_cmp, &save);
#else
	linkedlist_fetch(handle, id_name, id_cmp &save);
#endif
	print(&save);
	linkedlist_traverse(handle, print);
	printf("===============\n");

	linkedlist_destroy(handle);

	return 0;
}




