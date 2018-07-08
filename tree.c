#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct stu
{
	int id;
	char name[15];
	int score;
};

struct tree_head
{
	struct stu data;
	struct tree_head *left;
	struct tree_head *right;
};

static struct tree_head *tree = NULL;

void tree_add(struct tree_head **root, struct stu data);
void tree_traverse(struct tree_head *root);
void tree_balance(struct tree_head **root);
void draw(struct tree_head *root);
struct tree_head *tree_find(struct tree_head *root, void *find_data);
void print(struct stu s);

//int get_num(struct tree_head *root);
//struct tree_head *find_min(struct tree_head *root);
//void turn_left(struct tree_head **root);
//struct tree_head *find_max(struct tree_head *root);
//void turn_right(struct tree_head **root);
//void __draw(struct tree_head *root, int level);

int main(void)
{
	struct stu s;
	struct tree_head *t; 
	int i;
	int find_id = 100;
	char *find_name = "sut1";
	int arr[] = {9, 3, 2, 5, 6, 8, 4, 1, 7};

	for (i=0; i<sizeof(arr)/sizeof(*arr); i++)
	{
		s.id = arr[i];
		sprintf(s.name, "stu%d", arr[i]);
		s.score = 100 * arr[i];
		tree_add(&tree, s);
	}

//	tree_traverse(tree);
	
//	draw(tree);

	tree_balance(&tree);

//	printf("------------------\n");
//	tree_traverse(tree);

//	draw(tree);

	printf("+++++++++++++\n");
	t = tree_find(tree, &find_id);
	if (t == NULL)
		printf("Not find\n");
	else 
		print(t->data);

	return 0;
}

void tree_add(struct tree_head **root, struct stu data)
{
	if (*root == NULL)	
	{
		*root = malloc(sizeof(struct tree_head));
		if (*root == NULL)
			return;

		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	if (data.id < (*root)->data.id)
		tree_add(&(*root)->left, data);
	if (data.id > (*root)->data.id)
		tree_add(&(*root)->right, data);
}

void print(struct stu s)
{
	printf("%d %s %d\n", s.id, s.name, s.score);
}

void tree_traverse(struct tree_head *root)
{
	if (root == NULL)
		return;

	tree_traverse(root->left);
	print(root->data);
	tree_traverse(root->right);
}

int get_num(struct tree_head *root)
{
	if (root == NULL)
		return 0;
	return 1 + get_num(root->left) + get_num(root->right);
}

struct tree_head *find_min(struct tree_head *root)
{
	if (root->left == NULL)	
		return root;
	find_min(root->left);	
}

void turn_left(struct tree_head **root)
{
	struct tree_head *ptr = *root;

	*root = ptr->right;
	ptr->right = NULL;
	find_min(*root)->left = ptr;
}

struct tree_head *find_max(struct tree_head *root)
{
	if (root->right == NULL)	
		return root;
	find_max(root->right);	
}

void turn_right(struct tree_head **root)
{
	struct tree_head *ptr = *root;

	*root = ptr->left;
	ptr->left = NULL;
	find_max(*root)->right = ptr;
}

void tree_balance(struct tree_head **root)
{
	int num;

	if (*root == NULL)
		return;
	
	draw(tree);
	
	while (1)
	{
		num = get_num((*root)->left) - get_num((*root)->right);
		if (num >= -1 && num <= 1)
			break;
		if (num < -1)
			turn_left(root);
		if (num > 1)
			turn_right(root);
		getchar();
		draw(tree);
	}
	tree_balance(&(*root)->left);
	tree_balance(&(*root)->right);
}

void __draw(struct tree_head *root, int level)
{
	int i;

	if (root == NULL)
		return;
	
	__draw(root->right, level + 1);
	for (i=0; i<level; i++)
		printf("  ");
	print(root->data);
	__draw(root->left, level + 1);
}

void draw(struct tree_head *root)
{
	system("clear");
	__draw(root, 0);
}

struct tree_head *tree_find(struct tree_head *root, void *find_data)
{
	while (1)
	{
		if (root == NULL)
			break;

		if (*(int *)find_data == root->data.id)
			//	|| strcmp(find_data, root->data.name) == 0)	
		{
			break;	
		}
		else if (*(int *)find_data < root->data.id	)
			//	|| strcmp(find_data, root->data.name) < 0)	
		{
			printf("<<<<<<<<<<<<<<<<<<\n");
			root = root->left;	
		}
		else if (*(int *)find_data > root->data.id)
			//|| strcmp(find_data, root->data.name) > 1)	
			{
				printf(">>>>>>>>>>>>>>>>>\n");
				root = root->right;
			}
	}
	printf("*************\n");
	return root;
}


