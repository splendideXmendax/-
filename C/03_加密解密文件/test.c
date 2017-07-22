#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "des.h"

void menu()
{
	printf("=============================\n");
	printf("1 加密文件\n");
	printf("2 解密文件\n");
	printf("3 清屏\n");
	printf("4 退出\n");
	printf("=============================\n");
}

//加密文件
void DesEncFile()
{
	char src_path[512] = { 0 }; //源文件路径
	char dst_path[512] = { 0 }; //加密后文件的路径
	printf("请输入需要加密的文件：");
	scanf("%s", src_path);

	printf("请输入加密后的文件：");
	scanf("%s", dst_path);

	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;

	//以“rb”打开源文件
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("fopen src");
		goto END;
	}

	//以“wb”打开目的文件
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("fopen dst");
		goto END;
	}

	//循环操作
	//读一些内容，往另外一个文件，写内容
	//读多少，写多少，一点不差
	int len;
	char buf[1024 * 4]; //4k

	unsigned char dst[1024 * 8]; //密文
	int dst_len; //密文长度
	int ret;

	while (1)
	{
		//从源文件读取内容
		//len就是读取文件的大小
		len = fread(buf, 1, sizeof(buf), src_fp);
		if (len < 1024*4)
		{ //len < 4k  但是  > 0
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

		//读取的都是4k的内容， 读取内容先加密
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

//解密文件
void DesDecFile()
{
	char src_path[512] = { 0 }; //源文件路径
	char dst_path[512] = { 0 }; //加密后文件的路径
	printf("请输入需要解密的文件：");
	scanf("%s", src_path);

	printf("请输入解密后的文件：");
	scanf("%s", dst_path);

	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;

	//以“rb”打开源文件
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("fopen src");
		goto END;
	}

	//以“wb”打开目的文件
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("fopen dst");
		goto END;
	}

	//循环操作
	//读一些内容，往另外一个文件，写内容
	//读多少，写多少，一点不差
	int len;
	char buf[1024 * 4]; //4k

	unsigned char dst[1024 * 8]; //明文
	int dst_len; //明文长度
	int ret;

	while (1)
	{
		//从源文件读取内容，读取的内容是加密的内容
		//len就是读取文件的大小
		len = fread(buf, 1, sizeof(buf), src_fp);
		if (len < 1024 * 4)
		{ //len < 4k  但是  > 0
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

		//读取的都是4k的内容， 读取内容先加密
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
