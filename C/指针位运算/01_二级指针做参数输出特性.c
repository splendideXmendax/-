#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//func �ڲ�����ռ�, ������������ʵ��
//char ** ָ�� char *
void func(char ** p)
{
	char * tmp = (char *)malloc(100);

	*p = tmp; //��Ӹ�ֵ
}

int main(void)
{
	char * p = NULL;
	func(&p);
	if (p != NULL)
	{
		strcpy(p, "hello mike");
		printf("p = %s\n", p);

		free(p);
		p = NULL;
	}


	printf("\n");
	system("pause");
	return 0;
}
