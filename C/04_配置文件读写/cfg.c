#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CFGPATH "./cfg.dat"
#define SIZE (1024*8)   //处理8k

/*
功能：获取非空字符串
参数：
inbuf： 原始字符串buf首地址
outbuf：非空字符串buf首地址
返回值：
成功：0
失败：非0
*/
int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0){
		return -2;
	}

	//从左往右移动，如果当前字符为空，而且没有结束
	while (p[begin] == ' ') //或是使用 isspace()
	{
		begin++; //位置从右移动一位
	}

	//从右往左移动，如果当前字符为空
	while (p[end] == ' ' && end > 0)
	{
		end--; //往左移动
	}

	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //非空元素个数

	strncpy(outbuf, p + begin, n);
	outbuf[n] = '\0'; //结束符

	return 0;
}

/*
功能：
键值对（“key = value”）字符串更加键key查找对应的值value
参数：
keyval：键值对（“key = value”）字符串
pkey：键
buf：匹配键所对应的内容
len：匹配键所对应内容的长度
返回值：
成功：0
失败：非0
*/
int getKeyByValue(char *keyval, char *pkey, char *buf, int *len)
{
	if (keyval == NULL || pkey == NULL || buf == NULL || len == NULL)
	{
		return -1;
	}

	//辅助变量把形参接过来
	char *p = keyval; //"key1 =    valude1"

	//查看key是否在母串
	//查找 key1 是否在 "key1 =    valude1"
	p = strstr(p, pkey);
	if (NULL == p) //没有匹配键
	{
		return -2;
	}

	//重新设置起点位置，字符串跳过key值
	//"key1 =    valude1" -> " =    valude1"
	p = p + strlen(pkey);

	//查找是否包含=号
	p = strstr(p, "=");
	if (NULL == p)//没有
	{
		return -3;
	}

	//字符串跳过"="
	//" =    valude1" -> "    valude1"
	p = p + strlen("=");

	//获取非空字符串
	int ret = trimSpace(p, buf);
	if (ret != 0)
	{
		return ret;
	}

	//通过*操作符操作内存
	//间接赋值
	*len = strlen(buf);

	return 0;
}


int my_write(char *key, char *value)
{
	//1、打开文件
	FILE *fp = NULL;
	int ret = 0;

	//a、如果文件存在，不能以“w”打开，因为会清空
	//b、如果文件不存在，不能以“r”打开
	fp = fopen(CFGPATH, "r+");
	if (fp == NULL) //说明文件不存在，需要新建文件
	{
		fp = fopen(CFGPATH, "w+"); //再以写的方式，打开，目的为了新建文件
		if (fp == NULL)
		{
			perror("fopen");
			ret = -1;
			goto END;
		}
	}

	//判断文件大小
	//光标移动到末尾
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	if (size >= SIZE)
	{
		printf("文件大于8k， 不支持\n");
		ret = -3;
		goto END;
	}

	//把光标移动回开头
	rewind(fp);


	//写文件
	//a、文件有内容
	//b、文件没有内容

	char tmp[SIZE] = { 0 }; 
	char buf[1024] = { 0 };
	char *p = NULL;
	int flag = 0;

	//循环读取文件内容，每次读取一行
	while (1)
	{
		fgets(buf, sizeof(buf), fp);

		if (   feof(fp) ) //如果到文件结尾，结束
		{
			break;
		}

		//buf = "k2 = vvvvvv\n"
		p = strstr(buf, key); //查找字符串中有没有包含key
		if (p == NULL) //没有
		{
			strcat(tmp, buf);

			//中断本次循环
			continue;
		}

		//找到才能执行
		p = strstr(p, "="); //查找有没有=
		if (p == NULL)
		{
			strcat(tmp, buf);
			//中断本次循环
			continue;
		}

		//执行到这，说明这个key，需要改对应的value
		sprintf(buf, "%s = %s\n", key, value);
		strcat(tmp, buf);
		flag = 1; //说明，改key，不是追加
	}

	if (0 == flag) //追加
	{
		sprintf(buf, "%s = %s\n", key, value);
		strcat(tmp, buf);
	}

	//关闭文件，重写以写方式打开，重写文件
	fclose(fp);
	fp = NULL;

	fp = fopen(CFGPATH, "w+"); //再以写的方式，打开，目的为了清空文件
	if (fp == NULL)
	{
		perror("fopen");
		ret = -2;
		goto END;
	}

	//一行写入文件
	fputs(tmp, fp);
	

END:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return ret;
}

int my_read(char *key, char *value, int *len)
{
	FILE *fp = NULL;
	int ret = 0;

	//只读方式打开
	fp = fopen(CFGPATH, "r");
	if (fp == NULL)
	{
		perror("fopen");
		ret = -1;
		goto END;
	}

	char buf[1024] = { 0 };
	char * p;
	int flag = 0;

	while (1)
	{
		fgets(buf, sizeof(buf), fp);
		if (feof(fp)) //如果到文件结尾
		{
			break;
		}

		//buf = "k2 = vvvvvv\n"
		p = strstr(buf, key); //查找字符串中有没有包含key
		if (p == NULL) //没有
		{
			//中断本次循环
			continue;
		}

		//找到才能执行
		p = strstr(p, "="); //查找有没有=
		if (p == NULL)
		{
			//中断本次循环
			continue;
		}
		else //包含key值
		{
			flag = 1;
			break;
		}
	}

	if (0 == flag)
	{
		printf("没有这个key值\n");
		ret = -2;
		goto END;
	}

	//有，把key所对应的value取出来
	ret = getKeyByValue(buf, key, value, len);
	if (ret != 0)
	{
		goto END;
	}


END:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return ret;
}