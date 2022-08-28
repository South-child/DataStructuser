#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//打印单链表
void SListPrint(SLTNode* phead);

//销毁
void SListDestory(SLTNode** pphead);

//创建节点
SLTNode* BuySLTNode(SLTDataType x);


//头插
void SListPushFront(SLTNode** pphead, SLTDataType x);

//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);

//头删
void SListPopFront(SLTNode** pphead);

//尾删
void SListPopBack(SLTNode** pphead);

//查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos位置之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//在pos位置之后插入
void SListInsertAftre(SLTNode* pos, SLTDataType x);

// 删除pos位置
void SListErase(SLTNode** pphead, SLTNode* pos);

// 删除pos后面位置
void SListEraseAfter(SLTNode* pos);