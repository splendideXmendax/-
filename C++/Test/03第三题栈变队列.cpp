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
	//入队
	void Push(const int& val);
	//出队
	void Pop();
	//返回队首元素
	int& Front();
	//返回队尾元素
	int& Back();
	//判断队列是否为空
	bool Empty();
	//返回队列大小
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
		//获得栈顶元素
		s2.push(s1.top());
		s1.pop();
	}
	s2.pop();
	while (!s2.empty())
	{
		//获得栈顶元素
		s1.push(s2.top());
		s2.pop();
	}
}
//返回队首元素
int& Queue::Front()
{
	while (!s1.empty())
	{
		//获得栈顶元素
		s2.push(s1.top());
		s1.pop();
	}

	int sum = s2.top();

	while (!s2.empty())
	{
		//获得栈顶元素
		s1.push(s2.top());
		s2.pop();
	}
	return sum;
	
}
//返回队尾元素
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
