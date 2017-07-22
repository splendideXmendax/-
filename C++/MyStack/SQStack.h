#pragma once


#define MAXSIZE 1024
//��̬����ṹ��
typedef struct SEQSTACK
{
	void* data[MAXSIZE];
	int capacity;
	int size;

}SStack;

typedef void* SEQSTACK;

//��ʼ��
SEQSTACK Init_SeqStack();

//��ջ
int Push_SeqStack(SEQSTACK stack, void* data);

//��ջ
int Pop_SeqStack(SEQSTACK stack);

//���ջ��Ԫ��
void* Front_SeqStack(SEQSTACK stack);

//ջ�Ĵ�С
int Size_SeqStack(SEQSTACK stack);

//���ٶ���
void Destory_SeqStack(SEQSTACK stack);
