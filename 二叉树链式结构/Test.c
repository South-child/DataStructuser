#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;//存放数据
	struct BinaryTreeNode* left;//存放根节点的左子树
	struct BinaryTreeNode* right;//存放根节点的右子树
}BTNode;

//前序遍历
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
//后续遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);

}

//二叉树的结点个数
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}


//二叉树的叶子结点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//二叉树的高度
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}
//求第k层结点个数
int TreeKSize(BTNode* root,int k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;

	//求第K层，转换成求左右子树的第k-1层
	return TreeKSize(root->left, k - 1) + TreeKSize(root->right,k-1);
}
//二叉树的查找
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//若根节点不是，则先找左子树--利用其他变量先存储起来
	BTNode* left = TreeFind(root->left, x);
	if (left)
	{
		return left;
	}
	BTNode* right = TreeFind(root->right, x);
	if (right)
	{
		return right;
	}

	return NULL;
}

//创建一个简单的二叉树
BTNode* CreateTree()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	assert(n1);
	
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	assert(n2);

	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	assert(n3);

	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	assert(n4);

	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	assert(n5);

	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	assert(n6);

	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	assert(n7);

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;

	n1->left = n2;
	n1->right = n4;

	n2->left = n3;
	n2->right = NULL;

	n3->left = NULL;
	n3->right = n7;

	n4->left = n5;
	n4->right = n6;

	n5->left = NULL;
	n5->right = NULL;

	n6->left = NULL;
	n6->right = NULL;

	n7->left = NULL;
	n7->right = NULL;

	return n1;



}
int main()
{
	BTNode* root = CreateTree();

	PreOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");

	printf("Tree Size:%d\n", TreeSize(root));
	printf("Tree LeafSize:%d\n", TreeLeafSize(root));
	printf("Tree Height:%d\n", TreeHeight(root));
	printf("Tree K Size:%d\n", TreeKSize(root,4));
	printf("Tree Find:%p\n", TreeFind(root, 7));

	return 0;
}