#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

/*
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem);//���캯����n��elem����������
list(const list &lst);//�������캯����

*/

template<class T>
void printList(list<T> &mylist)
{
	for (list<T>::iterator it = mylist.begin(); it != mylist.end(); ++it)
	{
		cout << *it << endl;
	}
	//cout << endl;
}

void test01()
{
	list<int> mylist;
	mylist.push_back(10);
	mylist.push_back(20);
	mylist.push_front(30);
	mylist.push_front(40);

	list<int>::iterator it = mylist.begin();
	it++;
	it++;
	it++;
	mylist.insert(it, 100);
	printList(mylist);

	mylist.pop_back();
	mylist.pop_front();
}

class Person
{
	friend ostream& operator<<(ostream &os, Person &person)
	{
		os << "Name:" << person.mName << " Age:" << person.mAge;
		return os;
	}
public:
	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}

	bool operator==(const Person &person)
	{
		return this->mAge == person.mAge;
	}

	bool operator<(const Person &person)
	{
		return this->mAge < person.mAge;
	}

public:
	string mName;
	int mAge;
};




bool myComapre(Person &p)
{
	return p.mAge == 20;
}

//2. ɾ��
void test02()
{
	
	//erase ��λ��ɾ��
	//remove ��ֵɾ�� ɾ������ֵΪval

	list<int> mylist = { 1, 2, 3, 4, 5, 6,3, 7,3 };
	mylist.remove(3);
	printList(mylist);

	list<Person> listPerson = {
		Person("aaa", 10),
		Person("bbb", 20),
		Person("ccc", 20),
		Person("ddd", 30),
		Person("eee", 20),
	};

	listPerson.remove(Person("aaa", 20));
	//listPerson.remove_if( myComapre);
	printList(listPerson);

}

bool myCompareList(int v1,int v2)
{
	return v1 > v2;
}

bool myCompareListPerson(Person &v1, Person &v2)
{
	return v1.mAge > v2.mAge;
}
//3. ��ת���� ����
void test03()
{

	list<int> mylist = { 10, 2, 5, 4, 3 };
	//��ת����
	//mylist.reverse();
	
	//list�������ܹ�ʹ��sort�㷨����Ϊsort�㷨��Ҫ������ʵ�����
	//������List�����ṩ����˫�������

	//Ĭ����������
	mylist.sort(myCompareList);
	printList(mylist);

	cout << "----------" << endl;

	list<Person> listPerson = {
		Person("aaa", 10),
		Person("bbb", 20),
		Person("ccc", 20),
		Person("ddd", 30),
		Person("eee", 20),
	};
	//listPerson.sort(myCompareListPerson);
	listPerson.sort();
	printList(listPerson);
}




int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}