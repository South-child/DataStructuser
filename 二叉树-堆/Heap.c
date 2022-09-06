#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"


//打印堆
void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
//初始化	
void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->size = php->capacity = 0;
}
//销毁
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
//交换操作
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向上调整
void AdjustUp(HPDataType* a, int child)
{
	assert(a);

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//小根堆
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	//先求出根节点下的次小的孩子结点
	int minChild = parent * 2 + 1;//先假设左孩子是次小的
	while (minChild < n)
	{
		//小根堆
		if (minChild + 1 < n && a[minChild + 1] < a[minChild])
		{
			//如果右孩子比左孩子还小，则++
			minChild++;
		}

		if (a[minChild] < a[parent])
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//建堆
//void HeapCreate(HPDataType* a, int size)
//{
//	assert(a);
//	for (int i = 1; i < size; ++i)//从第二个结点开始遍历
//	{
//		//向上调整
//		AdjustUp(a, i);
//	}
//}
void HeapCreate(HPDataType* a, int size)
{
	assert(a);
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)//从最后一个叶结点的父结点开始到根结点
	{
		//向下调整
		AdjustDown(a, size, i);
	}
}

//插入x，并继续保持堆形态
void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	//考虑是否需要扩容
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;

		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;

	//需要判断插入的数据，是否能保持堆形态
	AdjustUp(php->a, php->size - 1);
}


// 删除堆顶元素，并保持堆形态
//每次找次大的或次小的 -- 所以时间复杂度为 O(logN)
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//向下调整
	AdjustDown(php->a, php->size, 0);
}
// 取堆顶元素
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}
//判空
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}
//返回堆中元素个数 
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
