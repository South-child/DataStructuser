#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//初始化
void StackInit(ST* ps);

//销毁
void StackDestroy(ST* ps);

//入栈
void StackPush(ST* ps, STDataType x);

//出栈
void StackPop(ST* ps);

//取栈顶元素
STDataType StackTop(ST* ps);

//判空
bool StackEmpty(ST* ps);

//计算栈中元素个数
int StackSize(ST* ps);