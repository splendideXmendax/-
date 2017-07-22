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
//��ʼ��
LinkQueue Init_LinkQueue();

//���
int  Push_LinkQueue(LinkQueue queue, void* data);

//����
int Pop_LinkQueue(LinkQueue queue);

//��ö�ͷԪ��
void* Front_LinkQueue(LinkQueue queue);

//��С
int Size_LinkQueue(LinkQueue queue);

//��������
int Destory_LinkQueue(LinkQueue queue);


#ifdef __cplusplus
}
#endif  /* __cplusplus */