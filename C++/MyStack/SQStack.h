#pragma once


#define MAXSIZE 1024
//动态数组结构体
typedef struct SEQSTACK
{
	void* data[MAXSIZE];
	int capacity;
	int size;

}SStack;

typedef void* SEQSTACK;

//初始化
SEQSTACK Init_SeqStack();

//入栈
int Push_SeqStack(SEQSTACK stack, void* data);

//出栈
int Pop_SeqStack(SEQSTACK stack);

//获得栈顶元素
void* Front_SeqStack(SEQSTACK stack);

//栈的大小
int Size_SeqStack(SEQSTACK stack);

//销毁队列
void Destory_SeqStack(SEQSTACK stack);
