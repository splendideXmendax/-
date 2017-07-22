#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include<map>
#include<ctime>
using namespace std;

class Employee
{
public:
	string mName;
	int mSalary;
};


//����Ա��
void CreateWorkers(list<Employee> &mylist)
{
	string seed = "ABCDEFGHIJ";
	for (int i = 0; i < seed.size(); ++i)
	{
		Employee em;
		em.mName = "Ա��";
		em.mName += seed[i];
		em.mSalary = 200000;
		
		mylist.push_back(em);
	}
}

#define SALE_DEPATMENT 1 //���۲���
#define DEVELOP_DEPATMENT 2 //�з�����
#define FINACIAL_DEPATMENT 3 //������
#define ALL_DEPATMENT 4 //���в���


//Ա������
void SetGroups(list<Employee> &workers, multimap<int, Employee> &groups)
{

	srand((unsigned int)time(NULL));

	//����Ա��
	for (list<Employee>::iterator it = workers.begin(); it != workers.end(); ++it)
	{
		int departmentID = rand() % 3 + 1; 
		groups.insert(make_pair(departmentID, *it));
	}

}

void ShowDepartmentWorkers(multimap<int, Employee> &groups, int depID)
{
	auto pos = groups.find(depID);
	int cnt = groups.count(depID);
	for (int i = 0; i < cnt; ++i)
	{
		cout << "Name:" << pos->second.mName << " Salary:" << pos->second.mSalary << endl;
		++pos;
	}
}


//��ӡÿһ��Ա������Ϣ
void ShowWorkersByGroup(multimap<int, Employee> &groups)
{
	cout << "���۲�����Ա����:" << endl;
	ShowDepartmentWorkers(groups, SALE_DEPATMENT);
	cout << "�з�������Ա����:" << endl;
	ShowDepartmentWorkers(groups, DEVELOP_DEPATMENT);
	cout << "��������Ա����:" << endl;
	ShowDepartmentWorkers(groups, FINACIAL_DEPATMENT);

}



int main(){


	//�洢Ա����Ϣ
	list<Employee> workers;
	//�洢����Ա����Ϣ
	multimap<int, Employee> groups;

	CreateWorkers(workers);
	SetGroups(workers, groups);
	ShowWorkersByGroup(groups);


	system("pause");
	return EXIT_SUCCESS;
}