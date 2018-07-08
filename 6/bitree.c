#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	int id;
	char name[20];
	int math;
};

struct tree_node
{
	struct stu data;
	struct tree_node *l;
	struct tree_node *r;
};

struct tree_node *tree = NULL;//指向树的根

int insert(struct tree_node **root, struct stu data)
{
	if(*root == NULL)
	{
		*root = malloc(sizeof(struct tree_node));
		if(*root == NULL)
			return -1;
		(*root)->data = data;
		(*root)->l = NULL;
		(*root)->r = NULL;
		return 0;
	}
	if(data.id < (*root)->data.id)
		insert(&(*root)->l, data);
	else
		insert(&(*root)->r, data);
}

void print(struct stu s)
{
	printf("%d  %s  %d\n", s.id, s.name, s.math);
}

void travel(struct tree_node *root)
{
	if(root == NULL)
		return ;
	print(root->data);
	travel(root->l);
	travel(root->r);
}

void destroy(struct tree_node *root)
{
	if(root == NULL)
		return ;
	destroy(root->l);
	destroy(root->r);
	free(root);
}

void _draw(struct tree_node *root, int level)
{
	int i;

	if(root == NULL)
		return ;
	_draw(root->r, level + 1);
	for(i = 0; i < level; i++)
		printf("  ");
	print(root->data);
	_draw(root->l, level + 1);
}

void draw(struct tree_node *root)
{
	system("clear");
	_draw(root, 0);//层次从0开始
	printf("\n\n");
	getchar();
}

int getnum(struct tree_node *root)
{
	if(root == NULL)
		return 0;
	return 1 + getnum(root->l) + getnum(root->r);
}

struct tree_node *findmin(struct tree_node *root)
{
	if(root == NULL)
		return NULL;
	if(root->l == NULL)
		return root;
	findmin(root->l);
}

struct tree_node *findmax(struct tree_node *root)
{
	if(root == NULL)
		return NULL;
	if(root->r == NULL)
		return root;
	findmax(root->r);
}

void turnright(struct tree_node **root)
{
	struct tree_node *node = *root;

	*root = node->l;
	node->l = NULL;
	findmax((*root))->r = node;
	draw(tree);
}

void turnleft(struct tree_node **root)
{
	struct tree_node *node = *root;

	*root = node->r;
	node->r = NULL;
	findmin((*root))->l = node;
	draw(tree);
}

void balance(struct tree_node **root)
{
	int num = 0;

	if(*root == NULL)
		return ;

	while(1)
	{
		num = getnum((*root)->l) - getnum((*root)->r);
		if(num >= -1 && num <= 1)
			break;
		else if(num < -1)
			turnleft(root);
		else
			turnright(root);
	}
	balance(&(*root)->l);
	balance(&(*root)->r);
}

struct stu *find(struct tree_node *root, int find_data)
{
	if(root == NULL)
		return NULL;
	if(find_data == root->data.id)
		return &(root)->data;
	else if(find_data > root->data.id)
		find(root->r, find_data);
	else
		find(root->l, find_data);
}

int delete(struct tree_node **root, int find_data)
{
	struct tree_node **node = root;
	struct tree_node *cur = NULL;

	while(*node != NULL && find_data != (*node)->data.id)
	{
		if(find_data > (*node)->data.id)
			*node = (*node)->r;
		else
			*node = (*node)->l;
	}
	if(*node == NULL)
		return -1;
	cur = *node;
	if(cur->l == NULL)
		*node = cur->r;
	*node = cur->l;
	findmax(cur->l)->r = cur->r;
	free(cur);
}

int main(void)
{
	int arr[] = {1,2,3,7,6,5,9,8,4};
	struct stu s, *data;
	int i;
	int find_id = 5;

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		s.id = arr[i];
		sprintf(s.name,"stu%d", arr[i]);
		s.math = 100 - arr[i];
		insert(&tree, s);//给树插入节点
	}

	travel(tree);//遍历树

	draw(tree);//画树

	balance(&tree);//平衡二叉数

	delete(&tree, find_id);//删除节点
	
	draw(tree);//画树

	balance(&tree);//平衡二叉数
/*
	printf("===================\n");
	data = find(tree, find_id);//查找节点
	if(data == NULL)
		printf("Not Find It!\n");
	else
		print(*data);
	printf("===================\n");
*/
	destroy(tree);//销毁树

	return 0;
}











