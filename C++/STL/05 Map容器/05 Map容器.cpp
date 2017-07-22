#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

void printMap(map<int, int> &m)
{
	for (auto v : m)
	{
		cout << "Key" << v.first << " Value��" << v.second << endl;
	}
	cout << endl;
}

void test01()
{

	map<int, int> m;
	//1. ��ͬ�ķ�ʽ
	m.insert(pair<int, int>(10, 10));
	m.insert(pair<int,int>(10, 20)); //key�ظ�������ʧ��
	m.insert(make_pair(20, 20));
	m.insert(map<int, int>::value_type(30, 30));
	/*
		�����ֲ��뷽ʽ����һ���������ظ�key�Ļ��������ʧ��!
	*/

	//2. ���������ֹ�����̫һ��
	m[10] = 40;
	/*
		�±귽ʽ�����key�����򸲸Ƕ�Ӧkey��ʵֵ
		��ͨ���±귽ʽ����һ�������ڵ�key��ʱ��map�ᴴ�����keyԪ�أ����Ҳ��뵽map��
	*/

	cout << "m[100]:" << m[100] << endl;

	printMap(m);
	
	//map��������˫�������
}

struct myComapre
{
	//map����ȻԪ��������pair�������ڱȽϹ����map����������key������
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
		cout << "Key" << v.first << " Value��" << v.second << endl;
	}
	cout << endl;
}


/*
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
*/

void test03()
{

	map<int, int> m = { { 7, 1 }, { 2, 2 }, { 6, 2 }, { 5, 2 } };
	auto pos = m.find(6);
	pos = m.lower_bound(6);
	pos = m.upper_bound(6);
	//����lower��upper����ֵ
	//epos��pair����
	auto epos = m.equal_range(6);
	if (pos == m.end())
	{
		cout << "����ʧ��!" << endl;
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