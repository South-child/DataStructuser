#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapPrint(HP* php);

void HeapInit(HP* php);
void HeapDestroy(HP* php);
// ����x�������ֶ���̬
void HeapPush(HP* php, HPDataType x);
// ɾ���Ѷ�Ԫ��
void HeapPop(HP* php);
// ���ضѶ���Ԫ��
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);



