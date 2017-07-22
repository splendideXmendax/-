#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<string>
using namespace std;

void printSet(set<int> &s)
{
	for (auto &val : s)
	{
		cout << val << " ";
	}
	cout << endl;
}

//1. set插入和删除
void test01()
{
	set<int> s;
	s.insert(10);
	s.insert(70);
	pair<set<int>::iterator, bool> ret=  s.insert(60);
	if (ret.second)
	{
		cout << "插入成功！" << endl;
	}
	else
	{
		cout << "插入失败！" << endl;
	}
	s.insert(50);
	ret = s.insert(60);
	if (ret.second)
	{
		cout << "插入成功！" << endl;
	}
	else
	{
		cout << "插入失败！" << endl;
	}

	//set<int>::iterator it = s.begin();
	//set的迭代器 双向只读迭代器 双向const迭代器
	printSet(s);

	s.erase(50);
	s.erase(s.begin());
	printSet(s);
}

void test02()
{
	pair<int, int> p;
	p.first = 10;
	p.second = 20;

	cout << p.first << " " << p.second << endl;


	pair<int, string> p2(100, "aaa");
	cout << p2.first << " " << p2.second << endl;

	//pair<string, int> p3 = make_pair("bbb", 200);
	auto p3 = make_pair("bbb", 200);
	cout << p3.first << " " << p3.second << endl;
	//mutiset支持重复元素  set元素必须唯一
	//set迭代器只读
	//set中的元素是自动排序的(默认是从小到大)
}

//3. 指定set默认是从大到小排序
//函数没有类型，函数对象是有类型
struct myCompareSet
{
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};
void test03()
{

	set<int, myCompareSet> s = { 6, 3, 8, 9, 1 };
	for (auto &val : s)
	{
		cout << val << " ";
	}
	cout << endl;

}

class Person
{
	friend ostream& operator<<(ostream &os, Person &person)
	{
		os << "Name:" << person.mName << " Age:" << person.mAge;
		return os;
	}
public:
	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}

	bool operator<(const Person &person) const
	{
		return this->mAge < person.mAge;
	}

public:
	string mName;
	int mAge;
};

//set存储自定义类型
void test04()
{
	set<Person> s;
	s.insert(Person("aaa", 20));
	s.insert(Person("bbb", 70));
	s.insert(Person("ccc", 60));
	s.insert(Person("ddd", 50));

	for (set<Person>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << "Name:" << it->mName << " Age:" << it->mAge << endl;
	}
}

/*
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数

*/
void test05()
{

#if 0
	set<int, myCompareSet> s = { 6, 3, 8, 9, 1 };
	set<int, myCompareSet>::iterator pos =  s.find(80);
	if (pos == s.end())
	{
		cout << "查找失败!" << endl;
	}
	else
	{
		cout << "ret = " << *pos << endl;
	}
#endif

	set<Person> s;
	s.insert(Person("aaa", 20));
	s.insert(Person("bbb", 70));
	s.insert(Person("ccc", 60));
	s.insert(Person("ddd", 50));

	set<Person>::iterator pos =  s.find(Person("ccc", 60));
	if (pos == s.end())
	{
		cout << "查找失败!" << endl;
	}
	else
	{
		cout << "ret = " << pos->mName << " " << pos->mAge << endl;
	}
}

/*
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/
void test06()
{
	//myCompareSet 如果从小到大 upper找到大于val的第一个元素
	//如果从大到小 ，和上面相反
	set<int> s = { 6, 3, 8, 9, 1 };
#if 0
 	auto pos = s.lower_bound(3);
	//auto pos = s.upper_bound(3); //1 3 6 8 9 
	                             //9 8 6 3 1
	if (pos == s.end())
	{
		cout << "查找失败!" << endl;
		return;
	}

	cout << "pos = " << *pos << endl;
#endif

	//返回lower和upper两个结果
	auto ret = s.equal_range(3);
	cout << "lower_bound val : " << *(ret.first) << endl;
	cout << "upper_bound val : " << *(ret.second) << endl;
}

int main(){

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();

	system("pause");
	return EXIT_SUCCESS;
}