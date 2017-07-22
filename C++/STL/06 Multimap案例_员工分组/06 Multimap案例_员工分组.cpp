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


//创建员工
void CreateWorkers(list<Employee> &mylist)
{
	string seed = "ABCDEFGHIJ";
	for (int i = 0; i < seed.size(); ++i)
	{
		Employee em;
		em.mName = "员工";
		em.mName += seed[i];
		em.mSalary = 200000;
		
		mylist.push_back(em);
	}
}

#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门
#define ALL_DEPATMENT 4 //所有部门


//员工分组
void SetGroups(list<Employee> &workers, multimap<int, Employee> &groups)
{

	srand((unsigned int)time(NULL));

	//遍历员工
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


//打印每一组员工的信息
void ShowWorkersByGroup(multimap<int, Employee> &groups)
{
	cout << "销售部门人员名单:" << endl;
	ShowDepartmentWorkers(groups, SALE_DEPATMENT);
	cout << "研发部门人员名单:" << endl;
	ShowDepartmentWorkers(groups, DEVELOP_DEPATMENT);
	cout << "财务部门人员名单:" << endl;
	ShowDepartmentWorkers(groups, FINACIAL_DEPATMENT);

}



int main(){


	//存储员工信息
	list<Employee> workers;
	//存储分组员工信息
	multimap<int, Employee> groups;

	CreateWorkers(workers);
	SetGroups(workers, groups);
	ShowWorkersByGroup(groups);


	system("pause");
	return EXIT_SUCCESS;
}