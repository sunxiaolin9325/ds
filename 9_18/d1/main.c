#include "func.h"

int main(void)
{
	PSTU pHead = NULL;
	STU data;
	int i;
	int del_id = 1002;
	char *del_name = "stu2";
	
	pHead = headNode_create();
	if (pHead == NULL)
		return -1;

	for (i = 0; i < 5; i++)
	{
		data.id = 1001 + i;	
		sprintf(data.name, "stu%d", i + 1);
		data.score = 100 - i;
		linkedList_insert(pHead, &data, 0);
	}

	linkedList_traverse(pHead);

#if 0
	linkedList_delete(pHead, del_name);
#else
	linkedList_find(pHead, &del_id);
#endif

	linkedList_traverse(pHead);
	linkedList_destroy(pHead);

	return 0;
}
