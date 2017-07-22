#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

template<class T>
void sort(T *array, int len)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < len - 1; i++) //冒泡
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				T tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

template<class T>
void Print(T *array, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << "\n";
}
class Person
{
	friend ostream & operator << (ostream & os, Person & person)
	{
		os << "Name " << person.mName << " Agen " << person.mAge;
		return os;
	}
	friend bool operator > (Person &person1, Person &person2)
	{
		return person1.mAge < person2.mAge;
	}

public:
	Person()
	{

	}
	Person(const Person& obj)
	{
		this->mName = obj.mName;
		this->mAge = obj.mAge;
//		cout << "拷贝构造" << endl;
	}
	Person(string name, int age)
	{
		mName = name;
		mAge = age;
//		cout << "构造" << endl;
	}

public:
	string mName;
	int mAge;
};


int main()
{
#if 0
	int a[10] = { 2, 3, 4, 5, 6, 78, 86, 5, 6 };
	sort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));

	char b[10] = "sdwgrewqa"; 
	sort(b, sizeof(b) - 1); 
	Print(b, sizeof(b) - 1); 
#endif

	Person pp[1000];	////对于对象可以直接重载字符串 < > 和 =
	for (int i = 0; i < 1000; i++)
	{
		pp[i] = Person("aaai", i + 100);
	}
//	Print(pp, 10);
	int a = clock();//
	sort<Person>(pp, 1000);
	int b = clock();//
	cout << endl;
	cout << b - a << "ms" << endl;
//	Print(pp, 10);



	system("pause");
	return 0;
}