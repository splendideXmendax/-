#pragma once

typedef	struct _LINKNODE
{
	struct _LINKNODE* next;
}LinkNode;

typedef struct _LISTLINK
{
	LinkNode hearde;
	int size;
}LinkList;
typedef void* ListNode;

#ifdef __cplusplus
extern "C"{
#endif

	//初始化
	ListNode Init_LinkList();
	//按位置插入
	void  Insert_LinkList(ListNode list, int pow, void* data);

	void fromInsert_LinkList(ListNode list, void* data);

	int findLastKNode(ListNode *list, int k, void(*myforeach)(void* data)); //显示倒数k位置的链表

	//普通遍历
	void  Foreach_LinkList(ListNode list, void(*myforeach)(void*data));
	//递归遍历
	void Foreach_LinkListA(ListNode list, void(*myforeach)(void* data));


	void Sort_LinkList(ListNode list, int(*compare)(void*, void*));//插入排序
	
	//按位置删除
	void  Remove_LinkList(ListNode list, int pow);
	//链表销毁
	void Destory_LinkList(ListNode list);



#ifdef __cplusplus
}
#endif













