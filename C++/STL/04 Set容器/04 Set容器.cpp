#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<string>
using namespace std;

void printSet(set<int> &s)
{
	for (auto &val : s)
	{
		cout << val << " ";
	}
	cout << endl;
}

//1. set�����ɾ��
void test01()
{
	set<int> s;
	s.insert(10);
	s.insert(70);
	pair<set<int>::iterator, bool> ret=  s.insert(60);
	if (ret.second)
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	s.insert(50);
	ret = s.insert(60);
	if (ret.second)
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}

	//set<int>::iterator it = s.begin();
	//set�ĵ����� ˫��ֻ�������� ˫��const������
	printSet(s);

	s.erase(50);
	s.erase(s.begin());
	printSet(s);
}

void test02()
{
	pair<int, int> p;
	p.first = 10;
	p.second = 20;

	cout << p.first << " " << p.second << endl;


	pair<int, string> p2(100, "aaa");
	cout << p2.first << " " << p2.second << endl;

	//pair<string, int> p3 = make_pair("bbb", 200);
	auto p3 = make_pair("bbb", 200);
	cout << p3.first << " " << p3.second << endl;
	//mutiset֧���ظ�Ԫ��  setԪ�ر���Ψһ
	//set������ֻ��
	//set�е�Ԫ�����Զ������(Ĭ���Ǵ�С����)
}

//3. ָ��setĬ���ǴӴ�С����
//����û�����ͣ�����������������
struct myCompareSet
{
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};
void test03()
{

	set<int, myCompareSet> s = { 6, 3, 8, 9, 1 };
	for (auto &val : s)
	{
		cout << val << " ";
	}
	cout << endl;

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

	bool operator<(const Person &person) const
	{
		return this->mAge < person.mAge;
	}

public:
	string mName;
	int mAge;
};

//set�洢�Զ�������
void test04()
{
	set<Person> s;
	s.insert(Person("aaa", 20));
	s.insert(Person("bbb", 70));
	s.insert(Person("ccc", 60));
	s.insert(Person("ddd", 50));

	for (set<Person>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << "Name:" << it->mName << " Age:" << it->mAge << endl;
	}
}

/*
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key);//���Ҽ�key��Ԫ�ظ���

*/
void test05()
{

#if 0
	set<int, myCompareSet> s = { 6, 3, 8, 9, 1 };
	set<int, myCompareSet>::iterator pos =  s.find(80);
	if (pos == s.end())
	{
		cout << "����ʧ��!" << endl;
	}
	else
	{
		cout << "ret = " << *pos << endl;
	}
#endif

	set<Person> s;
	s.insert(Person("aaa", 20));
	s.insert(Person("bbb", 70));
	s.insert(Person("ccc", 60));
	s.insert(Person("ddd", 50));

	set<Person>::iterator pos =  s.find(Person("ccc", 60));
	if (pos == s.end())
	{
		cout << "����ʧ��!" << endl;
	}
	else
	{
		cout << "ret = " << pos->mName << " " << pos->mAge << endl;
	}
}

/*
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
*/
void test06()
{
	//myCompareSet �����С���� upper�ҵ�����val�ĵ�һ��Ԫ��
	//����Ӵ�С ���������෴
	set<int> s = { 6, 3, 8, 9, 1 };
#if 0
 	auto pos = s.lower_bound(3);
	//auto pos = s.upper_bound(3); //1 3 6 8 9 
	                             //9 8 6 3 1
	if (pos == s.end())
	{
		cout << "����ʧ��!" << endl;
		return;
	}

	cout << "pos = " << *pos << endl;
#endif

	//����lower��upper�������
	auto ret = s.equal_range(3);
	cout << "lower_bound val : " << *(ret.first) << endl;
	cout << "upper_bound val : " << *(ret.second) << endl;
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