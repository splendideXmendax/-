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

	//��ʼ��
	ListNode Init_LinkList();
	//��λ�ò���
	void  Insert_LinkList(ListNode list, int pow, void* data);

	void fromInsert_LinkList(ListNode list, void* data);

	int findLastKNode(ListNode *list, int k, void(*myforeach)(void* data)); //��ʾ����kλ�õ�����

	//��ͨ����
	void  Foreach_LinkList(ListNode list, void(*myforeach)(void*data));
	//�ݹ����
	void Foreach_LinkListA(ListNode list, void(*myforeach)(void* data));


	void Sort_LinkList(ListNode list, int(*compare)(void*, void*));//��������
	
	//��λ��ɾ��
	void  Remove_LinkList(ListNode list, int pow);
	//��������
	void Destory_LinkList(ListNode list);



#ifdef __cplusplus
}
#endif













