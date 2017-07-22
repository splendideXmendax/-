#pragma once

typedef struct LinkNode
{
	struct LinkNode* next;

}LinkNode;
typedef struct ListQueue
{
	LinkNode header;
	int size;
	LinkNode reaz;

}ListQueue;

typedef void* LinkQueue;


#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
//初始化
LinkQueue Init_LinkQueue();

//入队
int  Push_LinkQueue(LinkQueue queue, void* data);

//出队
int Pop_LinkQueue(LinkQueue queue);

//获得对头元素
void* Front_LinkQueue(LinkQueue queue);

//大小
int Size_LinkQueue(LinkQueue queue);

//销毁链表
int Destory_LinkQueue(LinkQueue queue);


#ifdef __cplusplus
}
#endif  /* __cplusplus */