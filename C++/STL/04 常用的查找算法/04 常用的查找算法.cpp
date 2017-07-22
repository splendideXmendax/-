#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
find(iterator beg, iterator end, value)
*/
void test01()

/*
template<class _InIt,
class _Ty> inline
_InIt _Find(_InIt _First, _InIt _Last, const _Ty& _Val, false_type)
{	// find first matching _Val
for (; _First != _Last; ++_First)
if (*_First == _Val)
break;
return (_First);
}

*/
{
	vector<int> v = { 1, 2, 3, 4, 5 };

	vector<int>::iterator pos = find(v.begin(), v.end(), 30);
	if (pos == v.end())
	{
		cout << "查找失败！" << endl;
		return;
	}
	cout << "pos = " << *pos << endl;
}
/*
adjacent_find(iterator beg, iterator end, _callback);
*/
void test02()
{
	//查找相邻重复元素 1 2 3 4 4 5 6 7
	vector<int> v = { 1, 2, 3,3, 4, 5 };
	vector<int>::iterator it = adjacent_find(v.begin(),v.end());
	if (it == v.end())
	{
		cout << "查找失败!" << endl;
		return;
	}


	cout << "it = " << *it << endl;
	//如果说vector中放的是对象
	//1. 重载==号运算符
	//2. 手动添加两个对象的比较规则(函数对象)

	/*
	template<class _FwdIt,
	class _Pr> inline
	_FwdIt _Adjacent_find(_FwdIt _First, _FwdIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred with successor
	if (_First != _Last)
		for (_FwdIt _Firstb; (_Firstb = _First), ++_First != _Last; )
			if (_Pred(*_Firstb, *_First))
				return (_Firstb);
	return (_Last);
	}
	*/
	
}

/*
bool binary_search(iterator beg, iterator end, value);
*/
void test03()
{
	//二分查找法，使用前提序列必须是有序的
	//bianary_search默认的我们序列是升序的 1 2 3 4 5 6 7 8

	vector<int> v = { 1, 2, 3, 4, 5 };
	sort(v.begin(), v.end(), greater<int>());
	bool flag = binary_search(v.begin(),v.end(),4, greater<int>());
	//假如，vector存放的是Person对象
	//假如,vector不是默认的从小到大序列，而是从大到小，那么应该指定第四个参数
	if (flag)
	{
		cout << "找到了！" << endl;
	}
	else
	{
		cout << "没有!" << endl;
	}
}

class Person
{
public:
	Person(string name,int age)
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
find_if(iterator beg, iterator end, _callback);
*/


struct myCondition : public binary_function<Person*,Person*,bool>
{
	bool operator()(Person *person, Person *param) const
	{
		return person->mName == param->mName && person->mAge == param->mAge;
	}
};

void test04()
{

	/*
		template<class _InIt,
	class _Pr> inline
	_InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	for (; _First != _Last; ++_First)
		if (_Pred(*_First))
			break;
	return (_First);
	}
	*/
	vector<Person *> v;
	v.push_back(new Person("aaa", 10));
	v.push_back(new Person("bbb", 20));
	v.push_back(new Person("ccc", 30));
	v.push_back(new Person("ddd", 40));

	Person temp("ddd", 40);

	vector<Person *>::iterator it = find_if(v.begin(), v.end(),  bind2nd(myCondition(), &temp )  );
	if (it == v.end())
	{
		cout << "查找失败!" << endl;
		return;
	}
	cout << "Name:" << (*it)->mName << " Age:" << (*it)->mAge << endl;
	

	for_each(v.begin(), v.end(), [](Person *person){
		delete person;
	});

}

/*
count(iterator beg, iterator end, value);
*/

void test05()
{
	/*
		template<class _InIt,
	class _Ty> inline
	typename iterator_traits<_InIt>::difference_type
		_Count_np(_InIt _First, _InIt _Last, const _Ty& _Val)
	{	// count elements that match _Val
	typename iterator_traits<_InIt>::difference_type _Count = 0;

	for (; _First != _Last; ++_First)
		if (*_First == _Val)
			++_Count;
	return (_Count);
	}
	*/

	//统计元素出现的次数
	vector<int> v = { 1, 2, 3, 5, 3, 7, 3 };
	int n = count(v.begin(),v.end(), 3);
	cout << "n = " << n << endl;

	//如果是对象的话，那么对象需要重载==运算符
	//那么请问，如果容器中存储的是对象指针的话,怎么做？
}

/*
count_if(iterator beg, iterator end, _callback);
*/

struct myPersonCompare : public binary_function<Person*,Person*,bool>
{
	bool operator()(Person *person,Person *delPerson) const
	{
		return person->mName == delPerson->mName && person->mAge == delPerson->mAge;
	}
};
void  test06()
{

	/*
	template<class _InIt,
	class _Pr> inline
	typename iterator_traits<_InIt>::difference_type
		_Count_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// count elements satisfying _Pred
	typename iterator_traits<_InIt>::difference_type _Count = 0;

	for (; _First != _Last; ++_First)
		if (_Pred(*_First))
			++_Count;
	return (_Count);
	}
	*/
	vector<Person *> v;
	v.push_back(new Person("aaa", 10));
	v.push_back(new Person("bbb", 20));
	v.push_back(new Person("ccc", 30));
	v.push_back(new Person("ddd", 40));
	v.push_back(new Person("ccc", 30));

	Person temp("ddd", 40);

	int n = count_if(v.begin(), v.end(), bind2nd(myPersonCompare(),&temp));
	cout << "n = " << n << endl;

	for_each(v.begin(), v.end(), [](Person *person){
		delete person;
	});
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