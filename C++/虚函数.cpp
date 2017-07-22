#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	//基类如果写虚函数，一般情况目的为了让子类重写的
	//当一个类的内部有纯虚函数的时候，这个类不能被实例化
	//当类中有纯虚函数的时候，就把这个类叫做抽象类
	//当基类中有纯虚函数的话，子类就必须要实现这个函数
	//virtual void func() = 0; //纯虚函数
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
	多态实现条件
	父类指针或者引用指向子类对象
	子类重写父类的虚函数
*/

void test02()
{
	//1. 在编译阶段，编译器发现func是虚函数，编译器就知道不能在编译阶段确定函数调用
	//2. 在运行阶段，编译器发现类的内部有虚函数指针，编译器会根据虚函数指针找到虚函数表
	// 在虚函数表中找到对应的函数
	//3. 多态实现的原理是复杂的，如果不是为了发生多态，就不要写虚函数，如果父类写了虚函数
	//那么只有一个目的，就是为了让子类去重写的
	Base *b = new Derived;
	b->func();
	//b->Base::func();
}

void test03()
{

	//当把子类对象直接赋值给父类类型的对象的时候，编译器会剔除子类新增的成员。对象切割(对象切片)
	//父类指针或者引用指向子类对象不会发生对象切割
	Derived d;
	Base b = d;
	b.func();

}


//接口类
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