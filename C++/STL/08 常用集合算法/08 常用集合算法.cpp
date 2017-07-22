#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

void test01()
{
	
	//容器必须有序
	vector<int> v1, v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}

	for (int i = 5; i < 15; ++i)
	{
		v2.push_back(i);
	}

	vector<int> v3;
	v3.resize(min(v1.size(), v2.size()));

	vector<int>::iterator myend =  set_intersection(v1.begin(),v1.end(), v2.begin(),v2.end(), v3.begin());

	for (vector<int>::iterator it = v3.begin(); it != myend; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;


	//求两个容器的并集
	vector<int> v4;
	v4.resize(v1.size() + v2.size());

	myend = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v4.begin());
	for (vector<int>::iterator it = v4.begin(); it != myend; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//求两个集合的差集
	vector<int> v5;
	v5.resize(max(v1.size(),v2.size()));
	myend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());
	for (vector<int>::iterator it = v5.begin(); it != myend; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}