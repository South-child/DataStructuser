#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

//静态顺序表
//#define N 10
//struct SeqList
//{
//	SLDataType a[N];
//	int size;//存储数据的个数
//	int capacity;//数组总容量
//};

//动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	size_t size;//数组中元素实际个数
	size_t capacity;//数组总容量
}SL;

//顺序表初始化
void SLInit(SL* psl);
//顺序表销毁
void SLDestory(SL* psl);
//顺序表打印
void SLPrint(SL* psl);

//数据的管理 -- 增删查改

//尾插
void SLPushBack(SL* psl, SLDataType x);
//尾删
void SLPopBack(SL* psl);
//头插
void SLPushFront(SL* psl, SLDataType x);
//头删
void SLPopFront(SL* psl);

//顺序表查找-- 找到返回下表，没找到返回-1
int SLFind(SL* psl, SLDataType x);

//在pos位置插入数据
void SLInsert(SL* psl, size_t pos, SLDataType x);


//删除pos位置的数据
void SLEarse(SL* psl, size_t pos);

//修改pos位置的数据
void SLModify(SL* psl, size_t pos, SLDataType x);