#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//顺序表初始化
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->capacity = psl->size = 0;
}
//顺序表销毁
void SLDestory(SL* psl)
{
	assert(psl);

	free(psl->a);
	psl->a = NULL;
	psl->capacity = psl->size = 0;

}
//顺序表打印
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}
//扩容
void SLCheckCapacity(SL* psl)
{
	//如果没有空间或者空间不足，则需要扩容
	if (psl->size == psl->capacity)
	{
		int newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		psl->a = tmp;
		psl->capacity = newcapacity;
	}
}

//数据的管理 -- 增删查改
//尾插
void SLPushBack(SL* psl, SLDataType x)
{
	//assert(psl);

	////判断是否需要增容
	//SLCheckCapacity(psl);
	//psl->a[psl->size] = x;
	//psl->size++;

	//代码复用
	SLInsert(psl, psl->size, x);
}
//尾删
void SLPopBack(SL* psl)
{
	//assert(psl);
	////size要大于0才可以进行删除
	////暴力解决方法
	//assert(psl->size > 0);
	//psl->size--;
	////温柔解决方法
	///*if (psl->size == 0)
	//	return;*/

	//代码复用
	SLEarse(psl, psl->size - 1);
}
//头插
void SLPushFront(SL* psl, SLDataType x)
{
	////判断是否要增容
	//SLCheckCapacity(psl);

	////移动数据
	//for (int i = psl->size - 1; i >= 0; i--)
	//{
	//	psl->a[i+1] = psl->a[i];
	//}
	////插入数据
	//psl->a[0] = x;
	//psl->size++;

	//代码复用
	SLInsert(psl, 0, x);
}
//头删
void SLPopFront(SL* psl)
{
	//assert(psl);
	//assert(psl->size > 0);

	//for (int begin = 0; begin < psl->size - 1; begin++)
	//{
	//	psl->a[begin] = psl->a[begin + 1];
	//}

	//psl->size--;

	//代码复用
	SLEarse(psl, 0);
}

//顺序表查找-- 找到返回下表，没找到返回-1
int SLFind(SL* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
	{
		if (psl->a[i] == x)
			return i;
	}
	return -1;
}

//在pos位置插入数据
void SLInsert(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos <= psl->size);
	//插入数据之前需要判断是否需要扩容
	SLCheckCapacity(psl);
	//插入数据
	//挪动数据
	size_t end = psl->size;
	while (end > pos)
	{
		psl->a[end] = psl->a[end - 1];
		end--;
	}
	psl->a[pos] = x;
	psl->size++;

	//size_t end = psl->size - 1;
	//while (end >= pos) //pos等于0时，陷入死循环 因为end是无符号整形
	//{
	//	psl->a[end + 1] = psl->a[end];
	//	end--;
	//}
	//psl->a[pos] = x;
	//psl->size++;

}

//删除pos位置的数据
void SLEarse(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);
	int begin = pos;
	while (begin < psl->size - 1)
	{
		psl->a[begin] = psl->a[begin + 1];
		++begin;
	}
	psl->size--;
}

//修改pos位置的数据
void SLModify(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos < psl->size);
	psl->a[pos] = x;
}