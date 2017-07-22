#pragma once


#define MAXSIZE 1024
//��̬����ṹ��
typedef struct _DYNAMICQUEUE
{
	void*	data[MAXSIZE];
	int capacity; //����
	int size;	  //��С

}DQUEUE;

typedef void* DYNAMICQUEUE;

//��ʼ������
DYNAMICQUEUE Init_DynamicQueue();

//����
int Push_DynamicQueue(DYNAMICQUEUE queue,void* data);

//����
int Pop_DynamicQueue(DYNAMICQUEUE queue);

//���ͷԪ��
void* Front_DynamicQueue(DYNAMICQUEUE queue);

//��С
int Size_DynamicQueue(DYNAMICQUEUE queue);

//��������
int Destory_DynamicQueue(DYNAMICQUEUE queue);

