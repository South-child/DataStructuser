#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//打印单链表
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//销毁
void SListDestory(SLTNode** pphead)
{
	assert(pphead);

	SLTNode* cur = *pphead;

	while (cur != NULL)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

//创建节点
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;

}


//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);

	if (*pphead == NULL)//链表为空
	{
		*pphead = newnode;
	}
	else
	{
		//链表不为空
		//找尾
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//头删
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);

	assert(*pphead != NULL);

	SLTNode* tmp = *pphead;

	*pphead = tmp->next;
	free(tmp);
	tmp = NULL;

}

//尾删
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	assert(*pphead != NULL);

	//1.只有一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//2.多个节点
	else
	{
		//找尾 -- 删除尾结点，但要记录尾结点的前一个节点的位置		
		SLTNode* tail = *pphead;
		SLTNode* prev = *pphead;

		//方法一
		//while (tail->next != NULL)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}
		//free(tail);
		//tail = NULL;
		//prev->next = NULL;

		//方法二
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

//查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;

	while (cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//在pos位置之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)//pos位置在头节点，相当于头插
	{
		/*SLTNode* newnode = BuySLTNode(x);
		newnode->next = *pphead;
		*pphead = newnode;*/

		//代码复用
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySLTNode(x);

		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;

			//暴力检查，若pos不在链表中，则prev为空,pos传错了
			assert(prev);
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

//在pos位置之后插入
void SListInsertAftre(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 删除pos位置
//分析思考为什么不删除pos位置？
//单链表不适合删除当前位置，因为删除当前位置需要知到它的前一个位置，而找它的前一个需要从头开始找，这时时间复杂度就是O(N)
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)//头删
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		//pos = NULL; //无意义，因为传过来的不是二级指针，形参的改变不影响实参
		//可以在使用的时候，自己置空
	}
}

// 删除pos后面位置
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next != NULL);

	SLTNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
	//tmp = NULL; // 无意义
}