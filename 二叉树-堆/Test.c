#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//int main()
//{
//	int a[] = { 65, 100, 70, 32, 50, 60 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	HeapPrint(&hp);
//
//	HeapPush(&hp, 20);
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//	while (!HeapEmpty(&hp))
//	{
//		HPDataType tmp =  HeapTop(&hp);
//		printf("%d ", tmp);
//		HeapPop(&hp);
//	}
//	return 0;
//}

int main()
{
	int a[] = { 65, 100, 70, 32, 50, 60 };
	HeapCreate(a, sizeof(a) / sizeof(int));

	return 0;
}
