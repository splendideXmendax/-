#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
using namespace std;


void test()
{
	
	plus<int> myplus;

	cout << "ret = " << myplus(10, 20) << endl;
	cout << plus<int>()(100, 200) << endl;

	minus<int> m;
}



int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}