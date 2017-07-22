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
	//�����д�����ݶ���ͬ����
	int arr[] = { 1, 2, 3, 4, 6 };
	deque<int> d(arr, arr + sizeof(arr)/sizeof(int));

	vector<int> v = { 10, 20, 30, 40 };
	d.assign(v.begin(), v.end());

	deque<int> d1;
	d1.assign(v.begin(), v.end());
	printDeque(d1);

	//�������������е�Ԫ��
	d1.swap(d);

}

//deque�����ɾ��
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

//����ѧ����Ϣ
void CreateStudents(vector<Student> &v)
{
	string mNameSeed = "ABCDE";

	for (int i = 0; i < 5; ++i)
	{
		Student stu;
		stu.mScore = 0;
		stu.mName = "ѧ��";
		stu.mName += mNameSeed[i];

		v.push_back(stu);
	}
}

//ѧ�����
void SetScore(vector<Student> &v)
{
	srand((unsigned int)time(NULL));

	//����ѧ����Ϣ
	for (vector<Student>::iterator it = v.begin(); it != v.end(); ++it)
	{
		deque<int> dScores;
		for (int i = 0; i < 10; ++i)
		{
			int score = rand() % 50 + 50;
			dScores.push_back(score);
		}
		//�Է�����������
		sort(dScores.begin(), dScores.end());
		//ȥ����߷� ȥ����ͷ�
		dScores.pop_back();
		dScores.pop_front();
		//�ۼӷ�����
		int totalScore = 0;
		for (deque<int>::iterator dit = dScores.begin(); dit != dScores.end(); ++dit)
		{
			totalScore += (*dit);
		}
		//��ƽ����
		int avgScore = totalScore / dScores.size();
		//����ƽ����
		it->mScore = avgScore;

	}
}

//��ʾѧ����Ϣ
void ShowStudents(vector<Student> &v)
{
	//��С����
	sort(v.begin(), v.end());

	for (vector<Student>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
	{
		cout << "Score:" << rit->mScore  << " Name:" << rit->mName << endl;
	}


}

//3. ��ί��ְ���
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