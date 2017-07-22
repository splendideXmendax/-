#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<Ctime>
using namespace std;


#if 0
class Person
{
	
public:
	friend ostream & operator<<(ostream & os, Person & person)
	{
		os << "Name " << person.mName << " Age " << person.mAge;
		return os;
	}
public:
	Person()
	{
	}
	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};

struct MyComper
{
	bool operator()(Person & a, Person & b)
	{
		return a.mAge > b.mAge;
	}
};

template<typename T, typename P>
void insertSort(T* arr, int size, P  MyComper)
{
	for (int i = 1; i < size; i++)
	{
		if (MyComper(arr[i] ,arr[i - 1]))
		{
			T temp = arr[i];
			int j = i - 1;
			for (; j >= 0 && MyComper(temp, arr[j]); j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

template<class B>
void MyPrint(B *obj, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " obj " << obj[i] << endl;
	}
}

int main(void)
{
	Person* p = new Person[1000];
	for (int i = 0; i < 1000; i++)
	{
		p[i] = Person("qqqi", i + 888);
	}
	
//	MyPrint<Person>(p, 1000);
	int a = clock();//
	insertSort(p, 1000, MyComper());
	int b = clock();//
	cout << endl;
	cout << b - a << "ms" << endl;
//	MyPrint<Person>(p, 1000);

	cout << " hello world !" << endl;
	system("pause");
	return 0;
}
#endif 
