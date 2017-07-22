#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	typedef T* iterator;

public:
	MyArray()
	{
		this->mSize = 10;
		this->mCapacity = 10;
		this->pAddress = new T[10];

		for (int i = 0; i < 10; ++i)
		{
			this->pAddress[i] = i + 1;
		}
	}

	T* begin()
	{
		return this->pAddress;
	}

	T* end()
	{
		return this->pAddress + mSize;
	}

public:
	T *pAddress;
	int mSize;
	int mCapacity;
};


template<class T>
void myForeach(T beg ,T end)
{
	while (beg != end)
	{
		cout << *beg << " ";
		++beg;
	}
}

//容器提供迭代器，算法使用容器提供的迭代器

void test()
{
	MyArray<int> arr;


	MyArray<int>::iterator beg = arr.begin();
	MyArray<int>::iterator end = arr.end();

	myForeach(beg,end);

}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}