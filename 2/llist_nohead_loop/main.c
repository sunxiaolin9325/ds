#include "llist.h"

#define NUM 5

int main(void)
{
	llist *l;
	int find_id = 100;
	char *find_name = "stu4";

	l = llist_create(NUM);

	llist_display(l);
#if 1
	llist_delete(&l, &find_id);
#else
	llist_find(l, find_name);
#endif

	llist_display(l);

	llist_destroy(l);

	return 0;
}










