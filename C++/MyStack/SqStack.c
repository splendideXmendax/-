#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SQStack.h"
//��ʼ��
SEQSTACK Init_SeqStack()
{
	SStack* stack = malloc(sizeof(SStack));
	stack->size = 0;
	stack->capacity = MAXSIZE;
	memset(stack->data, 0, MAXSIZE);
	return stack;
}

//��ջ
int Push_SeqStack(SEQSTACK stack, void* data)
{
	if (NULL == stack)
	{
		return -1;
	}
	if (NULL == data)
	{
		return -2;
	}
	SStack* mystack = (SStack*)stack;
	mystack->data[mystack->size] = data;
	mystack->size++;
	return 0;
}

//��ջ
int Pop_SeqStack(SEQSTACK stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	SStack* mystack = (SStack*)stack;
	mystack->data[mystack->size - 1] = NULL;
	mystack->size--;
	return 0;
}

//���ջ��Ԫ��
void* Front_SeqStack(SEQSTACK stack)
{
	return NULL;
}

//ջ�Ĵ�С
int Size_SeqStack(SEQSTACK stack)
{
	return 0;
}

//���ٶ���
void Destory_SeqStack(SEQSTACK stack)
{
	return ;
}
