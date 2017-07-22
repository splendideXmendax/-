#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;


struct myPrint
{
	void operator()(int v,int param)
	{
		cout << "v = " << v << " param:" << param << endl;
	}
};

//for_each要求的是一个参数的函数对象
//事实上，myPrint是两个参数的函数对象


//适配器类
struct Target
{
public:
	Target(myPrint print, int param)
	{
		mPrint = print;
		mParam = param;
	}
	void operator()(int v)
	{
		mPrint(v, mParam);
	}
public:
	myPrint mPrint;
	int mParam;
};


Target myBind2nd(myPrint print, int param)
{
	return Target(print,param);
}


struct myPrint2 : public binary_function<int,int,void>
{
	void operator()(int v,int param) const
	{
	
	}

};
void test()
{
	
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	for_each(v.begin(), v.end(), myBind2nd(myPrint(),100));

	/*
	template<class _Fn2, class _Ty> inline
	binder2nd<_Fn2> bind2nd(const _Fn2& _Func, const _Ty& _Right)
	{
		//typename告诉编译器，_Fn2::second_argument_type是一个类型
		typename _Fn2::second_argument_type _Val(_Right);
		return (_STD binder2nd<_Fn2>(_Func, _Val));
	}
	*/


	/*
		binary_function

		template<class _Arg1, class _Arg2, class _Result>
		struct binary_function
		{
			typedef _Arg1 first_argument_type;
			typedef _Arg2 second_argument_type;
			typedef _Result result_type;
		};
	*/

}




int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}