#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

//销毁
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//需要判断栈是否满了,满了就要扩容
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;

		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

//取栈顶元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

//判空
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

//计算栈中元素个数
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}