#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//测试头插，尾插
void TestSListNode1()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListPushBack(&plist, 10);
	SListPushBack(&plist, 20);
	SListPushBack(&plist, 30);
	SListPrint(plist);


}

//测试头删尾删
void TestSListNode2()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 10);
	SListPushBack(&plist, 20);
	SListPushBack(&plist, 30);
	SListPushBack(&plist, 40);
	SListPushBack(&plist, 50);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);


}

//测试查找
void TestSListNode3()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 10);
	SListPushBack(&plist, 20);
	SListPushBack(&plist, 30);
	SListPushBack(&plist, 40);
	SListPushBack(&plist, 50);
	SListPrint(plist);

	int x = 0;
	scanf("%d", &x);
	SLTNode* pos = SListFind(plist, x);
	if (pos == NULL)
	{
		printf("没找到");
	}
	else
	{
		pos->data = (pos->data) * 10;
	}
	SListPrint(plist);
}

//测试插入
void TestSListNode4()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	int x = 0;
	scanf("%d", &x);
	SLTNode* pos = SListFind(plist, x);
	if (pos)
	{
		SListInsert(&plist, pos, 20);
		SListInsertAftre(pos, 30);
	}
	SListPrint(plist);
}

//测试删除pos后的节点
void TestSListNode5()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	int x = 0;
	scanf("%d", &x);
	SLTNode* pos = SListFind(plist, x);
	if (pos)
	{
		SListEraseAfter(pos);
		pos = NULL;
	}
	SListPrint(plist);
}
//测试删除pos位置的节点
void TestSListNode6()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	int x = 0;
	scanf("%d", &x);
	SLTNode* pos = SListFind(plist, x);
	if (pos)
	{
		SListErase(&plist, pos);
		pos = NULL;
	}
	SListPrint(plist);
}
int main()
{
	TestSListNode5();
	return 0;
}