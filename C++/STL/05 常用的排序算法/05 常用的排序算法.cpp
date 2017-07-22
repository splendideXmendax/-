#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>
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


//1. merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//合并两个优序序列
//merge必须合并两个是有序的，要不都是从小到大 要不都是从大到小vec
void test01()
{
	vector<int> v1, v2;
	for (int i = 0; i < 5; ++ i)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
	}

	vector<int> v3;
	//给v3开辟空间
	v3.resize(v1.size() + v2.size());

	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), greater<int>());
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//2. sort(iterator beg, iterator end, _callback)
void test02()
{
	vector<int> v = { 7, 2, 9, 3 };

	//sort算法容器必须提供的是随机访问迭代器
	sort(v.begin(), v.end());

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

}


//3. random_shuffle(iterator beg, iterator end) 
void test03()
{

	/*
	template<class _RanIt> inline
	void random_shuffle(_RanIt _First, _RanIt _Last)
	{	// shuffle [_First, _Last) using rand()
	_Rand_urng_from_func _Func;
	_STD shuffle(_First, _Last, _Func);
	}
	*/

	srand((unsigned int)time(NULL));

	//打乱容器的元素
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	random_shuffle(v.begin(),v.end());
	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;

}

//4. reverse(iterator beg, iterator end)
void test04()
{

	/*
	template<class _BidIt> inline
	void _Reverse(_BidIt _First, _BidIt _Last, bidirectional_iterator_tag)
	{	// reverse elements in [_First, _Last), bidirectional iterators
	for (; _First != _Last && _First != --_Last; ++_First)
		_STD iter_swap(_First, _Last);
	}
	*/

	//反转容器中的元素
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	reverse(v.begin(),v.end());

	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;


}


int main(){

	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}