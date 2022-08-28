#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//初始化
LTNode* ListInit();
//销毁
void ListDestory(LTNode* phead);
//打印
void ListPrint(LTNode* phead);

//尾插
void ListPushBack(LTNode* phead, LTDataType x);
//尾删
void ListPopBack(LTNode* phead);

//头插
void ListPushFront(LTNode* phead, LTDataType x);
//头删
void ListPopFront(LTNode* phead);

//查找
LTNode* ListFind(LTNode* phead, LTDataType x);
//在pos位置之前插入
void ListInsert(LTNode* pos, LTDataType x);
//删除pos位置
void ListErase(LTNode* pos);

//判断链表是否为空
bool ListEmpty(LTNode* phead);
