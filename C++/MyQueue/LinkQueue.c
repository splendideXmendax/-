#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkQueue.h"

//初始化
LinkQueue Init_LinkQueue()
{
	ListQueue* queue = malloc(sizeof(ListQueue));
	
	queue->header.next = NULL;
	queue->reaz.next = NULL;	//指 后面新加的节点
	queue->size = 0;

	return queue;
}

//入队
int  Push_LinkQueue(LinkQueue queue, void* data)
{
	if (NULL == queue)
	{
		return -1;
	}
	ListQueue* myqueue = (ListQueue*)queue;
	if (myqueue->size == 0)
	{
		myqueue->header.next = data;
		myqueue->reaz.next = data;
	}

	myqueue->reaz.next = data;
	LinkNode* pData = (LinkNode*)data;
	pData->next = NULL;
	return 0;
}

//出队
int Pop_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	ListQueue* myqueue = (ListQueue*)queue;
	LinkNode* pCurrent = myqueue->header.next;   //出列元素
	myqueue->header.next = pCurrent->next;
	if (0 == myqueue->size)
	{
		return 0;
	}
	if (1 == myqueue->size)
	{
		myqueue->header.next = NULL;
		myqueue->reaz.next = NULL;
		myqueue->size--;
		return 0;
	}
	return 0;

}

//获得对头元素
void* Front_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}
	ListQueue* myqueue = (ListQueue*)queue;
 	if (NULL == myqueue->header.next)
	{
		return NULL;
	}
	return myqueue->header.next;
}

//大小
int Size_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	ListQueue* myqueue = (ListQueue*)queue;
	return myqueue->size;
}

//销毁链表
int Destory_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	free(queue);
	return 0;
}


