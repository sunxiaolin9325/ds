#include "func.h"

int main(void)
{
	int find_id = 1005;
	STU *first = llist_create(NUM);

	llist_traverse(first);
	printf("=================\n");
#if 0
	llist_find(first, &find_id);
#else
	llist_delete(&first, &find_id);
#endif
	printf("=================\n");
	llist_traverse(first);

	llist_destroy(first);




	return 0;
}
