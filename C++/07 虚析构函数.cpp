#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base���캯��!" << endl;
	}

	virtual void func()
	{
		cout << "Base::func()!" << endl;
	}

	//���������� ��Ϊ�������������ʹ�����������
#if 0
	virtual ~Base()
	{
		cout << "Base��������!" << endl;
	}
#endif

	//��������������������Ҫ������Ҫʵ��
	//�������ڲ���������������������ô����Ҳ���ܹ���ʵ����������Ҳ�ǳ�����
	virtual ~Base() = 0;
};

Base::~Base()
{
	cout << "���ി����������!" << endl;
}

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived���캯��!" << endl;
	}

	virtual void func()
	{
		cout << "Derived::func()!" << endl;
	}

	~Derived()
	{
		cout << "Derived��������!" << endl;
	}
};


void test()
{
	//����ָ��ָ���������
	Base *b = new Derived;

	//���⣺ͨ������ָ��ȥ�ͷ���������ʱ����������п�����������(û�е����������������)
	delete b;

	//���๹�캯�����츸������
	//���๹�캯��������������

	//����������������������������
	//�����������������������

	Derived dd;
	Base& bb = dd;
	bb.func();


}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}