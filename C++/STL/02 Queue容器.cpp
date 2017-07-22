#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}

	~Person()
	{
		cout << "Person��������!" << endl;
	}
public:
	string mName;
	int mAge;
};
//1. ���д洢��ջ��  stack queue������������
void test01()
{
	//��ʼ������
	queue<Person> q;

	q.push(Person("aaa", 10));
	q.push(Person("bbb", 20));
	q.push(Person("ccc", 30));
	q.push(Person("ddd", 40));
	q.push(Person("eee", 50));
	
	while (!q.empty())
	{
		cout << "Name:" << q.front().mName << " Age:" << q.front().mAge << endl;
		q.pop();
	}

}

//���д洢�ڶ���
void test02()
{
	queue<Person *> *q = new queue<Person *>;

	q->push(new Person("aaa", 10));
	q->push(new Person("bbb", 20));
	q->push(new Person("ccc", 30));
	q->push(new Person("ddd", 40));
	q->push(new Person("eee", 50));

	//��������е�Ԫ��
	while (!q->empty())
	{
		Person *person = q->front();
		cout << "Name:" << q->front()->mName << " Age:" << q->front()->mAge << endl;
		//������ͷԪ��
		q->pop();
		//�ͷ��ڴ�
		if (person != NULL)
		{
			delete person;
			person = NULL;
		}
	}


	if (q != NULL)
	{
		delete q;
		q = NULL;
	}

}

int main(){

	test01();
	//test02();

	system("pause");
	return EXIT_SUCCESS;
}