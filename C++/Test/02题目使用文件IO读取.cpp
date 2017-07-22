#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<functional>

using namespace std;

class Person
{
	friend ofstream & operator << (ofstream & out, Person & per)
	{
		out << per.mName << "#";
		out << per.mAge << endl;
		return out;
	}
	friend ostream & operator << (ostream & os, Person & person)
	{
		os << "Name " << person.mName << " Agen " << person.mAge;
		return os;
	}

public:
	char mName[32];
	int mAge;
};
template<class T>
struct myPrint
{
	void operator()(T &val)
	{
		cout << val << " " << endl;
	}
};
struct mySort
{
	bool operator()(Person &val1, Person &val2)
	{
		return val1.mAge < val2.mAge;
	}
};
void StringDeal(char* str, vector<Person> & v) //�ַ�������
{
	char a[32] = { 0 };
	char *aa = a;
	strcpy(a, str);
	
	Person person;
	strtok(aa, "#");
	strcpy(person.mName, aa);
	aa = strtok(NULL, "#");
	person.mAge = atoi(aa);
	v.push_back(person);
}
void Read(vector<Person> & v, char* fileName)
{
	ifstream ism(fileName, ios::in);
	if (!ism)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	
	char buf[1024] = { 0 };
	while (true)
	{
		ism.getline(buf, 1024);
		cout << buf << endl;
		if (ism.eof())
		{
			break;
		}
		StringDeal(buf, v);
		memset(buf, 0, 1024);
	}
	cout << "�ļ���ȡ���" << endl;
	ism.close();
}
void wirte(vector<Person> & v, char* fileName)
{
	ofstream osm(fileName, ios::out);
	if (!osm)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		osm << *it;
	}
	cout << "д�����" << endl;
	osm.close();

}

int main(void)
{


	vector<Person> v;
	char* FileName = "./a.txt";
	Read(v, FileName); //Ҳ���������� ֻ��д���ʱ����뵽
	for_each(v.begin(), v.end(), myPrint<Person>());
	sort(v.begin(), v.end(), mySort());
	for_each(v.begin(), v.end(), myPrint<Person>());
	wirte(v, FileName);

	cout << " hello world !" << endl;
	system("pause");
	return 0;
}
