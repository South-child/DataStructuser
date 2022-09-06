#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//建堆
void HeapCreate(HPDataType* a, int size);
//初始化
void HeapInit(HP* php);
//销毁
void HeapDestroy(HP* php);
//插入x并保持堆
void HeapPush(HP* php, HPDataType x);
// 删除堆顶元素，并保持堆形态
void HeapPop(HP* php);
// 取堆顶元素
HPDataType HeapTop(HP* php);
//判空
bool HeapEmpty(HP* php);
//返回堆中元素个数 
int HeapSize(HP* php);

//打印堆
void HeapPrint(HP* php);
//交换
void Swap(HPDataType* p1, HPDataType* p2);
//向上调整
void AdjustUp(HPDataType* a, int child);
//向下调整
void AdjustDown(HPDataType* a, int n, int parent);



