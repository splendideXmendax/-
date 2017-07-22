#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

/*
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector &vec);//�������캯����

//���� ʹ�õڶ������캯�� ���ǿ���...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
*/

void printVector(vector<int> v)
{
	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;
}

void test01()
{
	int arr[] = { 2, 3, 4, 1, 9 };
	vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
	vector<int> v2(v.begin(), v.end());

	v2.assign(10, 10);



	printVector(v);
	printVector(v2);
	cout << (int)&v[0] << " " << (int)&v2[0] << endl;
	cout << "--------------" << endl;
	v.swap(v2);
	cout << (int)&v[0] << " " << (int)&v2[0] << endl;
	printVector(v);
	printVector(v2);

}

//2. resize��reserve������
void test02()
{
	vector<int> v;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	cout << "------------" << endl;
	v.resize(10);
	//v.reserve(10);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	printVector(v);

	cout << "------------" << endl;
	v.resize(5);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

	cout << "------------" << endl;
	//v.reserve(20);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;


	//reserveԤ���ڴ�ռ䣬resize�Ὺ���ڴ�ռ䣬���ҳ�ʼ������
	//��resize�Ĳ���С��Ԫ�ظ�������ô�����Ԫ�ػᱻ������������С����ı䣬������ڲ�������������ᱻ�������ҳ�ʼ��
	//���������ԭ������С�Ļ�����ô�������䣬�����ԭ��������Ļ�����������
}

//3. vector�����ɾ��
void test03()
{
	
	vector<int> v;
	//v.reserve(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	v.insert(v.begin() + 1, 100);
	v.insert(v.begin(), 3, 666);

	printVector(v);

	//����ɾ��
	v.erase(v.begin(),v.begin() + 2);
	printVector(v);

	v.erase(v.begin(), v.end());// v.clear();
	
	//ָ��λ��ɾ��
	v.erase(v.begin());
}

//4. ����ʹ��reverve��������Ч��
void test04()
{
	int *p = NULL;
	int count = 0;
	vector<int> v;
	v.reserve(100000);
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (&v[0] != p)
		{
			++count;
			p = &v[0];
		}
	}

	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	cout << "count = " << count << endl;

	//�ڴ���֪���洢����Ԫ�ص�����£� ������ǰ�����ڴ�
}

//swap�����ڴ�
void test05()
{
	vector<int> v;
	v.resize(100000);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	cout << "-------------" << endl;
	v.resize(5);

	vector<int>(v).swap(v);

	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
}

int main(){

	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	system("pause");
	return EXIT_SUCCESS;
}