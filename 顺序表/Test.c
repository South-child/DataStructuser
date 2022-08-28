#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void TestSeqList1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPrint(&s);

	SLPushFront(&s, 10);
	SLPushFront(&s, 20);
	SLPushFront(&s, 30);
	SLPushFront(&s, 40);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);


	SLDestory(&s);
}

//≤‚ ‘≤È’“”Î≤Â»Î
void TestSeqList2()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPrint(&s);

	int x = 0;
	scanf("%d", &x);
	int pos = SLFind(&s, x);
	if (pos != -1)
	{
		SLInsert(&s, pos, x * 100);

	}
	SLPrint(&s);
}

void TestSeqList3()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPrint(&s);

	int x = 0;
	scanf("%d", &x);
	int pos = SLFind(&s, x);
	if (pos != -1)
	{
		SLEarse(&s, pos);

	}
	SLPrint(&s);

	SLDestory(&s);

}
void TestSeqList4()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPrint(&s);

	SLPushFront(&s, 10);
	SLPushFront(&s, 20);
	SLPushFront(&s, 30);
	SLPushFront(&s, 40);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLDestory(&s);

}
int main()
{
	TestSeqList4();


	return 0;
}