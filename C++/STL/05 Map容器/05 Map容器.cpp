#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

void printMap(map<int, int> &m)
{
	for (auto v : m)
	{
		cout << "Key" << v.first << " Value：" << v.second << endl;
	}
	cout << endl;
}

void test01()
{

	map<int, int> m;
	//1. 相同的方式
	m.insert(pair<int, int>(10, 10));
	m.insert(pair<int,int>(10, 20)); //key重复，插入失败
	m.insert(make_pair(20, 20));
	m.insert(map<int, int>::value_type(30, 30));
	/*
		这三种插入方式工作一样，插入重复key的话，会插入失败!
	*/

	//2. 和上面三种工作不太一样
	m[10] = 40;
	/*
		下标方式，如果key存在则覆盖对应key的实值
		当通过下标方式访问一个不存在的key的时候，map会创建这个key元素，并且插入到map中
	*/

	cout << "m[100]:" << m[100] << endl;

	printMap(m);
	
	//map迭代器是双向迭代器
}

struct myComapre
{
	//map中虽然元素类型是pair，但是在比较规则里，map传进来的是key的类型
	bool operator()(int v1,int v2) const
	{
		return v1 > v2;
	}
};
void test02()
{
	map<int, int, myComapre> m = { { 7, 1 }, { 2, 2 }, { 6, 2 }, { 5, 2 } };
	
	for (auto v : m)
	{
		cout << "Key" << v.first << " Value：" << v.second << endl;
	}
	cout << endl;
}


/*
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/

void test03()
{

	map<int, int> m = { { 7, 1 }, { 2, 2 }, { 6, 2 }, { 5, 2 } };
	auto pos = m.find(6);
	pos = m.lower_bound(6);
	pos = m.upper_bound(6);
	//返回lower和upper两个值
	//epos是pair类型
	auto epos = m.equal_range(6);
	if (pos == m.end())
	{
		cout << "查找失败!" << endl;
		return;
	}
	cout << "pos = " << pos->first << " " << pos->second << endl;
}


int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}