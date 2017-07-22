#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	//�������д�麯����һ�����Ŀ��Ϊ����������д��
	//��һ������ڲ��д��麯����ʱ������಻�ܱ�ʵ����
	//�������д��麯����ʱ�򣬾Ͱ���������������
	//���������д��麯���Ļ�������ͱ���Ҫʵ���������
	//virtual void func() = 0; //���麯��
	virtual void func(){}
	virtual void func2()
	{
		cout << "Base::func2()" << endl;
	}
	void func3()
	{
		cout << "Base::func3()" << endl;
	}
public:
	int mA;
};

class Derived : public Base
{
public:
	
};


void test01()
{
	Base b;

	typedef void(*pFunc)();

	((pFunc)* ((int *)*(int *)&b + 1))();

}

/*
	��̬ʵ������
	����ָ���������ָ���������
	������д������麯��
*/

void test02()
{
	//1. �ڱ���׶Σ�����������func���麯������������֪�������ڱ���׶�ȷ����������
	//2. �����н׶Σ���������������ڲ����麯��ָ�룬������������麯��ָ���ҵ��麯����
	// ���麯�������ҵ���Ӧ�ĺ���
	//3. ��̬ʵ�ֵ�ԭ���Ǹ��ӵģ��������Ϊ�˷�����̬���Ͳ�Ҫд�麯�����������д���麯��
	//��ôֻ��һ��Ŀ�ģ�����Ϊ��������ȥ��д��
	Base *b = new Derived;
	b->func();
	//b->Base::func();
}

void test03()
{

	//�����������ֱ�Ӹ�ֵ���������͵Ķ����ʱ�򣬱��������޳����������ĳ�Ա�������и�(������Ƭ)
	//����ָ���������ָ��������󲻻ᷢ�������и�
	Derived d;
	Base b = d;
	b.func();

}


//�ӿ���
class MyInterface
{
public:
	virtual void func01() = 0;
	virtual void func02() = 0;
	virtual void func03() = 0;
	virtual void func04() = 0;
};

class My :public MyInterface
{
public:
	virtual void func01(){}
	virtual void func02() {}
	virtual void func03() {}
	virtual void func04() {}
};

void test04()
{
	MyInterface *myi = new My;
	myi->func01();
}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}