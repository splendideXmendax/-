#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

//初始化
ListNode Init_LinkList()
{
	LinkList* list = malloc(sizeof(LinkList));
	list->hearde.next = NULL;
	list->size = 0;
	return list;
}
/******************************************************************************/
//前插
void fromInsert_LinkList(ListNode list,  void* data)
{

	if (NULL == list)
	{
		return;
	}
	LinkList* mylist = (LinkList*)list;

	LinkNode* pCurrent = (LinkNode*)data;
	pCurrent->next = mylist->hearde.next;
	mylist->hearde.next = pCurrent;

}
//位置插入 //后插
void Insert_LinkList(ListNode list, int pow, void* data)
{
	if (NULL == list)
	{
		return;
	}
	LinkList* mylist = (LinkList*)list;
	if (pow < 0 || pow > mylist->size)
	{
		pow = mylist->size;
	}
	LinkNode* oCurrent = &(mylist->hearde); //链表中间中间变量
	for (int i = 0; i < pow; i++)
	{
		oCurrent = oCurrent->next;
	}
	LinkNode* pdata = (LinkNode*)data; //待插入元素
	pdata->next = oCurrent->next;		//从后面插入
	oCurrent->next = (LinkNode*)data;
}
/*************************************************************************/
//void Foreach_LinkList(LinkNode* list, myforeach(void* data))

void Foreach_LinkList(ListNode list, void(*myforeach)(void* data))//普通遍历
{
	if (NULL == list)
	{
		return;
	}
	LinkList* mylist = (LinkList*)list;
	LinkNode* oCurrent = &(mylist->hearde);
	while (oCurrent->next != NULL)
	{
		oCurrent = oCurrent->next;
		myforeach(oCurrent);
	}
}
int findLastKNode(ListNode *list, int k, void(*myforeach)(void* data)) //显示倒数k位置的链表
{
	LinkList* mylist = (LinkList*)list;
	LinkNode* oCurrent = &(mylist->hearde);
	LinkNode* pCurrent = &(mylist->hearde);
	if (NULL == list)
	{
		return -1;
	}
	int i = 0;
	for (i = 0; oCurrent->next != NULL; ++i)
	{
		oCurrent = oCurrent->next;
	}
	printf("%d\n", i);
	int z = 0;
	int j = 0;
	if (k + 1 > j )
	{
		return -1;
	}
	for (j = 0; j < i - k +1; j++)
	{
		pCurrent = pCurrent->next;
	}
	myforeach(pCurrent);
	return 0;
}
void Sort_LinkList(ListNode list, int(*compare)(void*, void*))//插入排序
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == compare)
	{
		return;
	}
	LinkList* mylist = (LinkList*)list;

	LinkNode* pCurrent = mylist->hearde.next;
	LinkNode* p = pCurrent;
	LinkNode* llp = NULL;
	for (; pCurrent->next != NULL; pCurrent = pCurrent->next)	
	{
		if (compare(pCurrent,pCurrent->next)) 
		{
			llp = pCurrent->next;		//llp待插
			pCurrent->next = llp->next;
		
			for (p = &(mylist->hearde); compare(llp, p->next); p = p->next);
			llp->next = p->next;
			p->next = llp;
			pCurrent = &(mylist->hearde);
		}
	}
}

/***********************************************************************************/

//void RevetseFortach_LinKList(LinkNode* node, void(*myforeach)(void* data))
//{
//	if (NULL == node)
//	{
//		return;
//	}
//	myforeach(node);
//	node = node->next;
//	Remove_LinkList(node, myforeach);
//}
/*
void RevetseForeach_LinkListA(ListNode list, void(*myforeach)(void* data))//递归遍历
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == myforeach)
	{
		return;
	}
	LinkList* mylist = (LinkList*)list;
	LinkNode* node = mylist->hearde.next;
	RevetseFortach_LinKList(node, myforeach);
}
*/
/*************************************************************************************/
//指定位置删除
void Remov_LinkList(ListNode list, int pow)
{
	if (NULL == list)
	{
		return;
	}
	LinkList* mylist = (LinkList*)list;
	if (pow < 0 || pow > mylist->size)
	{
		pow = mylist->size;
	}
	LinkNode* pCurrent = &(mylist->hearde);
	for (int i = 0; i < pow; i++)
	{
		pCurrent = pCurrent->next;
	}
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
}
//销毁链表
void Destory_LinkList(ListNode list)
{
	if (NULL == list)
	{
		return;
	}
	LinkList* mylist = (LinkList*)list;
	mylist->hearde.next = NULL;
}





