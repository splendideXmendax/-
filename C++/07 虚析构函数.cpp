#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base构造函数!" << endl;
	}

	virtual void func()
	{
		cout << "Base::func()!" << endl;
	}

	//虚析构函数 分为：虚析构函数和纯虚析构函数
#if 0
	virtual ~Base()
	{
		cout << "Base析构函数!" << endl;
	}
#endif

	//纯虚析构函数，编译器要求我们要实现
	//如果类的内部包含纯虚析构函数，那么此类也不能够被实例化，此类也是抽象类
	virtual ~Base() = 0;
};

Base::~Base()
{
	cout << "基类纯虚析构函数!" << endl;
}

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived构造函数!" << endl;
	}

	virtual void func()
	{
		cout << "Derived::func()!" << endl;
	}

	~Derived()
	{
		cout << "Derived析构函数!" << endl;
	}
};


void test()
{
	//父类指针指向子类对象
	Base *b = new Derived;

	//问题：通过父类指针去释放子类对象的时候，子类对象有可能清理不彻底(没有调用子类的析构函数)
	delete b;

	//父类构造函数构造父类数据
	//子类构造函数构造子类数据

	//子类析构函数清理子类新增数据
	//父类的析构函数清理父类数据

	Derived dd;
	Base& bb = dd;
	bb.func();


}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}