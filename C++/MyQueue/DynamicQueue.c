#include"DynamicQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ʼ������
DYNAMICQUEUE Init_DynamicQueue()
{
	DQUEUE*queue = malloc(sizeof(DQUEUE));
	if (NULL == queue)
	{
		return NULL;
	}
	queue->capacity = MAXSIZE;
	queue->size = 0;
	memset(queue->data, 0, MAXSIZE); //������0
	return queue;
}


//����
int Push_DynamicQueue(DYNAMICQUEUE queue, void* data)
{
	if (NULL == queue)
	{
		return -1;
	}
	if (NULL == data)
	{
		return -2;
	}
	DQUEUE* myqueue = (DQUEUE*)queue;
	if (myqueue->size == MAXSIZE)
	{
		return -3;
	}
	myqueue->data[myqueue->size] = data;
	myqueue->size++;
	return 0;
}
//����
int Pop_DynamicQueue(DYNAMICQUEUE queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	DQUEUE* myqueue = (DQUEUE*)queue;
	for (int i = 0; i < myqueue->size; i++)
	{
		myqueue->data[i] = myqueue->data[i + 1];
		myqueue->data[myqueue->size - 1] = NULL;
	}
	myqueue->size--;
	return 0;
}

//���ͷԪ��
void* Front_DynamicQueue(DYNAMICQUEUE queue);

//��С
int Size_DynamicQueue(DYNAMICQUEUE queue);

//��������
int Destory_DynamicQueue(DYNAMICQUEUE queue);
