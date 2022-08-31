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

void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);

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



