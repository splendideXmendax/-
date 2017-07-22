#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;


//1. for_each

struct myPrint
{
	myPrint()
	{
		mCount = 0;
	}

	void operator()(int val)
	{
		cout << val << " ";
		++mCount;
	}

	int mCount;
};

void test01()
{	
	vector<int> v = { 1, 2, 3, 4, 5 };
	myPrint print;
	myPrint p =  for_each(v.begin(), v.end(), print);
	cout << endl;
	cout << "Count:" << print.mCount << endl;
	cout << "Count:" << p.mCount << endl;
}

//2. transform 将一个或者两个容器中元素，经过运算之后，放到目标容器中
struct myTtransform
{
	//返回类型由目标容器元素类型决定
	//参数类型由源容器元素类型决定
	int operator()(int val)
	{
		return val + 100;
	}
};
void test02()
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	vector<int> dst;
	vector<int> dst2;
	dst.resize(v.size());
	dst2.resize(v.size());

	/*
	template<class _InIt, class _OutIt, class _Fn1> 
	inline _OutIt _Transform(_InIt _First, _InIt _Last,_OutIt _Dest, _Fn1 _Func)
	{
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Func(*_First);
		return (_Dest);
	}
	*/
	transform(v.begin(), v.end(), dst.begin(), myTtransform());
	for_each(dst.begin(), dst.end(), [](int val)
	{ 
		cout << val << " "; 
	});
	cout << endl;

	//将两个容器的元素经过相加，放到dst2容器中
	transform(v.begin(), v.end(), dst.begin(), dst2.begin(), plus<int>() );
	for_each(dst2.begin(), dst2.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}


int main(){

	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}