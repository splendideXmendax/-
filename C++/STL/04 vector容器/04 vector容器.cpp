#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

/*
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。

//例子 使用第二个构造函数 我们可以...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
*/

void printVector(vector<int> v)
{
	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;
}

void test01()
{
	int arr[] = { 2, 3, 4, 1, 9 };
	vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
	vector<int> v2(v.begin(), v.end());

	v2.assign(10, 10);



	printVector(v);
	printVector(v2);
	cout << (int)&v[0] << " " << (int)&v2[0] << endl;
	cout << "--------------" << endl;
	v.swap(v2);
	cout << (int)&v[0] << " " << (int)&v2[0] << endl;
	printVector(v);
	printVector(v2);

}

//2. resize和reserve的区别
void test02()
{
	vector<int> v;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	cout << "------------" << endl;
	v.resize(10);
	//v.reserve(10);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	printVector(v);

	cout << "------------" << endl;
	v.resize(5);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

	cout << "------------" << endl;
	//v.reserve(20);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;


	//reserve预留内存空间，resize会开辟内存空间，并且初始化对象
	//当resize的参数小于元素个数，那么多余的元素会被丢弃，容量大小不会改变，如果大于参数，多余参数会被创建并且初始化
	//容量如果比原来容量小的话，那么容量不变，如果比原来容量大的话，更新容量
}

//3. vector插入和删除
void test03()
{
	
	vector<int> v;
	//v.reserve(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	v.insert(v.begin() + 1, 100);
	v.insert(v.begin(), 3, 666);

	printVector(v);

	//区间删除
	v.erase(v.begin(),v.begin() + 2);
	printVector(v);

	v.erase(v.begin(), v.end());// v.clear();
	
	//指定位置删除
	v.erase(v.begin());
}

//4. 合理使用reverve可以提升效率
void test04()
{
	int *p = NULL;
	int count = 0;
	vector<int> v;
	v.reserve(100000);
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (&v[0] != p)
		{
			++count;
			p = &v[0];
		}
	}

	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	cout << "count = " << count << endl;

	//在大致知道存储多少元素的情况下， 可以提前申请内存
}

//swap收缩内存
void test05()
{
	vector<int> v;
	v.resize(100000);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	cout << "-------------" << endl;
	v.resize(5);

	vector<int>(v).swap(v);

	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
}

int main(){

	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	system("pause");
	return EXIT_SUCCESS;
}