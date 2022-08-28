#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void TestList1()
{
	LTNode* plist = ListInit();
	//Œ≤≤Â
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	//Œ≤…æ
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopBack(plist);

}
void TestList2()
{
	LTNode* plist = ListInit();
	//Œ≤≤Â
	//ListPushBack(plist, 1);
	//ListPushBack(plist, 2);
	//ListPushBack(plist, 3);
	//ListPushBack(plist, 4);
	//ListPrint(plist);

	//Õ∑≤Â
	ListPushFront(plist, 10);
	ListPushFront(plist, 20);
	ListPushFront(plist, 30);
	ListPushFront(plist, 40);
	ListPrint(plist);

	//Õ∑…æ
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListPopFront(plist);

}

void TestList3()
{
	LTNode* plist = ListInit();
	//Œ≤≤Â
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	//≤È’“
	LTNode* pos = ListFind(plist, 1);
	if (pos)
	{
		ListInsert(pos, 30);
	}
	ListPrint(plist);
}
int main()
{
	TestList3();
	return 0;
}