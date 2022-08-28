#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//初始化
LTNode* ListInit()
{
	LTNode* guard = (LTNode*)malloc(sizeof(LTNode));
	if (guard == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	guard->next = guard;
	guard->prev = guard;

	return guard;
}
//销毁
void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
//创建结点
LTNode* BuyListNode(x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;

	return newnode;
}

//判断链表是否为空
bool ListEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

//打印
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//尾插
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/

	ListInsert(phead, x);
}
//尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	/*LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;

	phead->prev = prev;
	prev->next = phead;
	free(tail);
	tail = NULL;*/

	ListErase(phead->prev);
}

//头插
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* cur = phead->next;
	
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = cur;
	cur->prev = newnode;*/

	ListInsert(phead->next, x);

}
//头删
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	//LTNode* first = phead->next;
	//LTNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;

	ListErase(phead->next);

}

//查找
LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;

}
//在pos位置之前插入
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* prev = pos->prev;
	
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
//删除pos位置
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}