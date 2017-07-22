#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "des.h"

void menu()
{
	printf("=============================\n");
	printf("1 �����ļ�\n");
	printf("2 �����ļ�\n");
	printf("3 ����\n");
	printf("4 �˳�\n");
	printf("=============================\n");
}

//�����ļ�
void DesEncFile()
{
	char src_path[512] = { 0 }; //Դ�ļ�·��
	char dst_path[512] = { 0 }; //���ܺ��ļ���·��
	printf("��������Ҫ���ܵ��ļ���");
	scanf("%s", src_path);

	printf("��������ܺ���ļ���");
	scanf("%s", dst_path);

	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;

	//�ԡ�rb����Դ�ļ�
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("fopen src");
		goto END;
	}

	//�ԡ�wb����Ŀ���ļ�
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("fopen dst");
		goto END;
	}

	//ѭ������
	//��һЩ���ݣ�������һ���ļ���д����
	//�����٣�д���٣�һ�㲻��
	int len;
	char buf[1024 * 4]; //4k

	unsigned char dst[1024 * 8]; //����
	int dst_len; //���ĳ���
	int ret;

	while (1)
	{
		//��Դ�ļ���ȡ����
		//len���Ƕ�ȡ�ļ��Ĵ�С
		len = fread(buf, 1, sizeof(buf), src_fp);
		if (len < 1024*4)
		{ //len < 4k  ����  > 0
		   //len == 0
			ret = DesEnc((unsigned char *)buf, len, dst, &dst_len);
			if (ret != 0)
			{
				printf("DesEnc ret = %d\n", ret);
				goto END;
			}

			fwrite(dst, 1, dst_len, dst_fp);


			break;
		}

		//��ȡ�Ķ���4k�����ݣ� ��ȡ�����ȼ���
		ret = DesEnc_raw((unsigned char *)buf, len, dst, &dst_len);
		if (ret != 0)
		{
			printf("DesEnc_raw ret = %d\n", ret);
			goto END;
		}

		fwrite(dst, 1, dst_len, dst_fp);
	}


END:
	if (src_fp != NULL)
	{
		fclose(src_fp);
	}

	if (dst_fp != NULL)
	{
		fclose(dst_fp);
	}


}

//�����ļ�
void DesDecFile()
{
	char src_path[512] = { 0 }; //Դ�ļ�·��
	char dst_path[512] = { 0 }; //���ܺ��ļ���·��
	printf("��������Ҫ���ܵ��ļ���");
	scanf("%s", src_path);

	printf("��������ܺ���ļ���");
	scanf("%s", dst_path);

	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;

	//�ԡ�rb����Դ�ļ�
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("fopen src");
		goto END;
	}

	//�ԡ�wb����Ŀ���ļ�
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("fopen dst");
		goto END;
	}

	//ѭ������
	//��һЩ���ݣ�������һ���ļ���д����
	//�����٣�д���٣�һ�㲻��
	int len;
	char buf[1024 * 4]; //4k

	unsigned char dst[1024 * 8]; //����
	int dst_len; //���ĳ���
	int ret;

	while (1)
	{
		//��Դ�ļ���ȡ���ݣ���ȡ�������Ǽ��ܵ�����
		//len���Ƕ�ȡ�ļ��Ĵ�С
		len = fread(buf, 1, sizeof(buf), src_fp);
		if (len < 1024 * 4)
		{ //len < 4k  ����  > 0
			//len == 0
			ret = DesDec((unsigned char *)buf, len, dst, &dst_len);
			if (ret != 0)
			{
				printf("DesDec ret = %d\n", ret);
				goto END;
			}

			fwrite(dst, 1, dst_len, dst_fp);

			break;
		}

		//��ȡ�Ķ���4k�����ݣ� ��ȡ�����ȼ���
		ret = DesDec_raw((unsigned char *)buf, len, dst, &dst_len);
		if (ret != 0)
		{
			printf("DesDec_raw ret = %d\n", ret);
			goto END;
		}

		fwrite(dst, 1, dst_len, dst_fp);
	}

END:
	if (src_fp != NULL)
	{
		fclose(src_fp);
	}

	if (dst_fp != NULL)
	{
		fclose(dst_fp);
	}
}

int main(void)
{
	int cmd;
	while (1)
	{
		menu();

		printf("cmd: ");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1:
			DesEncFile();
			break;
		case 2:
			DesDecFile();
			break;
		case 3:
			system("cls");
			break;
		case 4:
			exit(0);
		}
	}


	printf("\n");
	system("pause");
	return 0;
}
