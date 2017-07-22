#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector> //动态数组
#include<string>
#include<algorithm> //算法头文件
using namespace std;

void myPrintInt(int val)
{
	cout << val << " ";
}

struct MyPrintFunctorInt
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//1. 容器中存储基础数据类型
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//容器提供迭代器，如果容器支持遍历
	vector<int>::iterator beg = v.begin();
	vector<int>::iterator end = v.end();

#if 0
	while (beg != end)
	{
		cout << *beg << " ";
		++beg;
	}

#endif

#if 0
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}

#endif

#if 1
	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;
#endif

	for_each(v.begin(), v.end(), myPrintInt);
	for_each(v.begin(), v.end(), MyPrintFunctorInt());
}

//2. 存储对象
class Person
{
public:
	Person(string name,int age)
	{
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};
void test02()
{

	vector<Person> v;
	v.push_back(Person("aaa", 10));
	v.push_back(Person("bbb", 20));
	v.push_back(Person("ccc", 30));
	v.push_back(Person("ddd", 40));
	v.push_back(Person("eee", 50));

	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "Name:" << (*it).mName << " Age:" << (*it).mAge << endl;
		//cout << "Name:" << it->mName << " Age:" << it->mAge << endl;
	}

}

//3. 存储对象指针
void test03()
{

	vector<Person*> v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "Name:" << (*it)->mName << " Age:" << (*it)->mAge << endl;
	}

}

//4. 容器嵌套容器
void test04()
{
	vector< vector<int> > v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(10 + i);
		v2.push_back(20 + i);
		v3.push_back(30 + i);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (auto it = v.begin(); it != v.end(); ++it)
	{
		//*it 是 vector<int>类型
		for (auto tt = it->begin(); tt != it->end(); ++tt)
		{
			//*tt是int类型
			cout << *tt << " ";
		}
		cout << endl;
	}

	
}

int main(){

	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}