#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<stack>
using namespace std;
class Queue
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	//���
	void Push(const int& val);
	//����
	void Pop();
	//���ض���Ԫ��
	int& Front();
	//���ض�βԪ��
	int& Back();
	//�ж϶����Ƿ�Ϊ��
	bool Empty();
	//���ض��д�С
	int Size();
};
void Queue::Push(const int& val)
{
	s1.push(val);
}
void Queue::Pop()
{
	while (!s1.empty())
	{
		//���ջ��Ԫ��
		s2.push(s1.top());
		s1.pop();
	}
	s2.pop();
	while (!s2.empty())
	{
		//���ջ��Ԫ��
		s1.push(s2.top());
		s2.pop();
	}
}
//���ض���Ԫ��
int& Queue::Front()
{
	while (!s1.empty())
	{
		//���ջ��Ԫ��
		s2.push(s1.top());
		s1.pop();
	}

	int sum = s2.top();

	while (!s2.empty())
	{
		//���ջ��Ԫ��
		s1.push(s2.top());
		s2.pop();
	}
	return sum;
	
}
//���ض�βԪ��
int& Queue::Back()
{
	return s1.top();
}

bool Queue::Empty()
{
	return s1.empty();
}
int Queue::Size()
{
	if (s2.size() != 0)
	{
		return s2.size() + s1.size();
	}
	return s1.size();
}

int main(void)
{
	Queue p;
	p.Push(1);
	p.Push(2);
	p.Push(3);
	p.Push(4);
	p.Push(5);
	p.Push(6);
	p.Push(7);

	while (1)
	{
		if (p.Empty())
		{
			break;
		}
		cout << p.Front() << "  ";
		cout << p.Back() << "  ";
		cout << p.Size() << endl;
		p.Pop();
	}


	cout << " hello world !" << endl;
	system("pause");
	return 0;
}
