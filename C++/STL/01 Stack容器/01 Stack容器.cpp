#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//1. stakc�洢����������
void test01()
{
	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	//��ӡջ�����е�Ԫ��
	while (!s.empty())
	{
		//���ջ��Ԫ��
		int val = s.top();
		cout << val << " ";
		//����ջ��Ԫ��
		s.pop();
	}

	cout << "size:" << s.size() << endl;

}

class Person
{
public:
	Person(string name,int age)
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

//2. stack�洢����
void test02()
{
	stack<Person> s;

	s.push(Person("aaa", 10));
	s.push(Person("bbb", 20));
	s.push(Person("ccc", 30));
	s.push(Person("ddd", 40));
	s.push(Person("eee", 50));

	while (s.size() > 0)
	{
		Person &person =  s.top();
		cout << "Name:" << person.mName << " Age:" << person.mAge << endl;
		s.pop();
	}

}

//�洢����ָ��
void test03()
{

	stack<Person *> s;
	s.push(new Person("aaa", 10));
	s.push(new Person("bbb", 20));
	s.push(new Person("ccc", 30));
	s.push(new Person("ddd", 40));
	s.push(new Person("eee", 50));

	while (s.size() > 0)
	{
		Person *person = s.top();
		cout << "Name:" << person->mName << " Age:" << person->mAge << endl;
		s.pop();

		if (person != NULL)
		{
			delete person;
			person = NULL;
		}
	}


	//�ڶ��Ͽ���stakc����
	//stack<int> *ss = new stack<int>;

}


int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}