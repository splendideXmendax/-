#pragma once


#define MAXSIZE 1024
//动态数组结构体
typedef struct _DYNAMICQUEUE
{
	void*	data[MAXSIZE];
	int capacity; //容量
	int size;	  //大小

}DQUEUE;

typedef void* DYNAMICQUEUE;

//初始化数组
DYNAMICQUEUE Init_DynamicQueue();

//入列
int Push_DynamicQueue(DYNAMICQUEUE queue,void* data);

//出列
int Pop_DynamicQueue(DYNAMICQUEUE queue);

//获得头元素
void* Front_DynamicQueue(DYNAMICQUEUE queue);

//大小
int Size_DynamicQueue(DYNAMICQUEUE queue);

//销毁链表
int Destory_DynamicQueue(DYNAMICQUEUE queue);

