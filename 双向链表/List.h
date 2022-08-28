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

//��ʼ��
LTNode* ListInit();
//����
void ListDestory(LTNode* phead);
//��ӡ
void ListPrint(LTNode* phead);

//β��
void ListPushBack(LTNode* phead, LTDataType x);
//βɾ
void ListPopBack(LTNode* phead);

//ͷ��
void ListPushFront(LTNode* phead, LTDataType x);
//ͷɾ
void ListPopFront(LTNode* phead);

//����
LTNode* ListFind(LTNode* phead, LTDataType x);
//��posλ��֮ǰ����
void ListInsert(LTNode* pos, LTDataType x);
//ɾ��posλ��
void ListErase(LTNode* pos);

//�ж������Ƿ�Ϊ��
bool ListEmpty(LTNode* phead);
