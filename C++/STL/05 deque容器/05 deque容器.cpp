#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;

void printDeque(deque<int> &d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	//容器中存放数据都是同类型
	int arr[] = { 1, 2, 3, 4, 6 };
	deque<int> d(arr, arr + sizeof(arr)/sizeof(int));

	vector<int> v = { 10, 20, 30, 40 };
	d.assign(v.begin(), v.end());

	deque<int> d1;
	d1.assign(v.begin(), v.end());
	printDeque(d1);

	//交换两个容器中的元素
	d1.swap(d);

}

//deque插入和删除
void test02()
{
	
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	printDeque(d);
	d.pop_back();
	d.pop_front();

	printDeque(d);

	d.insert(d.begin() + 1, 10, 1);
	printDeque(d);

	vector<int> v = { 10, 20, 30, 40 };
	d.insert(d.begin(), v.begin(), v.end());
	printDeque(d);
}


class Student
{
public:
	bool operator<(const Student &stu)
	{
		return this->mScore < stu.mScore;
	}
public:
	string mName;
	int mScore;
};

//创建学生信息
void CreateStudents(vector<Student> &v)
{
	string mNameSeed = "ABCDE";

	for (int i = 0; i < 5; ++i)
	{
		Student stu;
		stu.mScore = 0;
		stu.mName = "学生";
		stu.mName += mNameSeed[i];

		v.push_back(stu);
	}
}

//学生打分
void SetScore(vector<Student> &v)
{
	srand((unsigned int)time(NULL));

	//遍历学生信息
	for (vector<Student>::iterator it = v.begin(); it != v.end(); ++it)
	{
		deque<int> dScores;
		for (int i = 0; i < 10; ++i)
		{
			int score = rand() % 50 + 50;
			dScores.push_back(score);
		}
		//对分数进行排序
		sort(dScores.begin(), dScores.end());
		//去除最高分 去除最低分
		dScores.pop_back();
		dScores.pop_front();
		//累加分数和
		int totalScore = 0;
		for (deque<int>::iterator dit = dScores.begin(); dit != dScores.end(); ++dit)
		{
			totalScore += (*dit);
		}
		//求平均分
		int avgScore = totalScore / dScores.size();
		//保存平均分
		it->mScore = avgScore;

	}
}

//显示学生信息
void ShowStudents(vector<Student> &v)
{
	//从小到大
	sort(v.begin(), v.end());

	for (vector<Student>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
	{
		cout << "Score:" << rit->mScore  << " Name:" << rit->mName << endl;
	}


}

//3. 评委打分案例
void test03()
{
	vector<Student> v;
	CreateStudents(v);
	SetScore(v);
	ShowStudents(v);

}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}