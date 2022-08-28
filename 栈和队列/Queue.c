#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
//销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;

	while (cur)
	{
		QNode* del = cur;
		free(del);
		cur = cur->next;
	}
	pq->head = pq->tail = NULL;
}
//入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//首先需要申请一个新结点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}

	//队列为空
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	//队列不为空
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

	pq->size++;
}
//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail =  NULL;
	}
	else
	{
		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
		del = NULL;
	}
	pq->size--;
}

//取队头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}
//取队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

//判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

//计算队列大小
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}