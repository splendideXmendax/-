#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"
typedef struct _PERSON{
	void* next;
	char name[64];
	int age;
}Person;
void MyPrint(void* data)
{
	Person* mydata = data;
	printf("%s ,%d \n", mydata->name, mydata->age);
	return;
}
int MyFairly(void* data1, void*data2)
{
	Person* mydata1 = data1;
	Person* mydata2 = data2;
	if (mydata1->age > mydata2->age)
	{
		return 1;
	}
	return 0;


}

void test()
{
		//初始化队列
		LinkList* list = Init_LinkList();
		//创建数据
		Person p1 = { NULL,"aaa", 10 };
		Person p2 = { NULL, "bbb", 20 };
		Person p3 = { NULL, "ccc", 30 };
		Person p4 = { NULL, "ddd", 40 };
		Person p5 = { NULL, "eee", 50 };
		Person p6 = { NULL, "fff", 60 };
		Person p7 = { NULL, "ggg", 70 };

		Insert_LinkList(list, 1, &p1);
		Insert_LinkList(list, 1, &p3);
		Insert_LinkList(list, 1, &p5);
		Insert_LinkList(list, 1, &p2);
		Insert_LinkList(list, 1, &p4);
		Insert_LinkList(list, 1, &p6);

		Foreach_LinkList(list, MyPrint);
//		findLastKNode(list, 5, MyPrint);
		//前插
	//	fromInsert_LinkList(list, &p7);
//		Foreach_LinkList(list, MyPrint);

		Sort_LinkList(list, MyFairly);//插入排序
		printf("\n");

		Foreach_LinkList(list, MyPrint);
}
int main(void)
{

	test();

	printf("\n");
	system("pause");
	return 0;
}
