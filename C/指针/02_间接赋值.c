#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int a = 10;
	//int * ָ��int
	int * p = NULL;
	p = &a; //ָ��ָ��˭���Ͱ�˭�ĵ�ַ�����ָ�����

	//*p���ǲ���p���ڴ棬�ǲ���p��ָ����ڴ�
	*p = 11;

	printf("*p = %d, a = %d\n", *p, a);


	printf("\n");
	system("pause");
	return 0;
}
