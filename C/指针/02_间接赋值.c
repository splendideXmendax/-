#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int a = 10;
	//int * 指向int
	int * p = NULL;
	p = &a; //指针指向谁，就把谁的地址给这个指针变量

	//*p不是操作p的内存，是操作p所指向的内存
	*p = 11;

	printf("*p = %d, a = %d\n", *p, a);


	printf("\n");
	system("pause");
	return 0;
}
