#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>
#include<list>
#include<deque>
#include<numeric>
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
		cout << "destrcutor!" << endl;
	}
public:
	string mName;
	int mAge;
};

//accumulate(iterator beg, iterator end, value) 
//将容器的元素进行累加操作，返回累加结果

struct myPlus
{
	int operator()(int val,Person &p)
	{
		return val + p.mAge;
	}
};

void test01()
{

	vector<int> v = { 1, 2, 3, 4, 5 };
	int sum = accumulate(v.begin(),v.end(),0);
	cout << "sum = " << sum << endl;

	vector<Person> v2;
	v2.push_back(Person("aaa", 10));
	v2.push_back(Person("bbb", 20));
	v2.push_back(Person("ccc", 30));

	int totalAge = accumulate(v2.begin(), v2.end(), 0, myPlus());
	cout << "totalAge:" << totalAge << endl;

}

//fill
void test02()
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	fill(v.begin(),v.end(),100);
	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;
}

int main(){

	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}