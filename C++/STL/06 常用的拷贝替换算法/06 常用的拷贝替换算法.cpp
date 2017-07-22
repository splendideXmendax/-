#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>
#include<list>
#include<deque>

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
/*
copy(iterator beg, iterator end, iterator dest)
replace(iterator beg, iterator end, oldvalue, newvalue)
replace_if(iterator beg, iterator end, _callback, newvalue)
swap(container c1, container c2)
*/

void test01()
{
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(),v1.end(),v2.begin());

	for (auto val : v2)
	{
		cout << val << " ";
	}
	cout << endl;
}

void test02()
{

	deque<int> v1 = { 1, 2, 3, 4, 5, 6 };
	deque<int> v2 = { 10, 20, 30, 40, 50, 60 };

	swap(v1, v2); //v1.swap(v2)

}


struct myCondition : public binary_function<int,int,bool>
{
	bool operator()(int val,int param) const
	{
		return val > param;
	}
};

void test03()
{

	/*
	template<class _FwdIt,
	class _Ty> inline
	void _Replace(_FwdIt _First, _FwdIt _Last,
		const _Ty& _Oldval, const _Ty& _Newval)
	{	// replace each matching _Oldval with _Newval
	for (; _First != _Last; ++_First)
		if (*_First == _Oldval)
			*_First = _Newval;
	}
	*/
	
	vector<int> v = { 1, 2, 3, 4, 5 };

	replace(v.begin(), v.end(), 4, 400);

	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;


	replace_if(v.begin(), v.end(), bind2nd( myCondition() , 3), 100);

	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;

}



int main(){

	//test01();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}