#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;//存放数据
	struct BinaryTreeNode* left;//存放根节点的左子树
	struct BinaryTreeNode* right;//存放根节点的右子树
}BTNode;


typedef BTNode* QDataType;
typedef struct QueueNode
{
	struct Queue* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);
//入队
void QueuePush(Queue* pq, QDataType x);
//出队
void QueuePop(Queue* pq);

//取队头元素
QDataType QueueFront(Queue* pq);
//取队尾元素
QDataType QueueBack(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);

//计算队列大小
int QueueSize(Queue* pq);