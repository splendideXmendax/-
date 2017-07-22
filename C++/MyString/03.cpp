#include "03.h"


MyString::MyString() //�޲ι��� 
{
	this->mSize = 0;
	this->pAddress = new char[1];
	this->pAddress[0] = '\0';
}
MyString::MyString(int n, char c) //�вι��죬ָ����С�ͳ�ʼֵ
{
	this->mSize = n;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, c, n);
	this->pAddress[n] = '\0';
}
MyString::MyString(const MyString& str) //��������
{
	this->mSize = str.mSize;
	this->pAddress = new char[this->mSize + 1];
	strcpy(this->pAddress, str.pAddress);
}
MyString& MyString::operator=(const MyString& str) //��ֵ���������
{
	this->mSize = str.mSize;
	if (NULL != this->pAddress)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
	this->pAddress = new char[this->mSize + 1];
	strcpy(this->pAddress, str.pAddress);
	return *this;
}
MyString& MyString::operator=(const char* str) //��ֵ���������
{
	this->mSize = strlen(str);
	if (NULL != this->pAddress)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
	this->pAddress = new char[this->mSize + 1];
	strcpy(this->pAddress, str);
	return *this;
}
MyString::~MyString() //��������
{
	this->mSize = 0;
	if (NULL != this->pAddress)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
}


MyString MyString::operator+(const MyString& str) //�Ӻ����������
{
	MyString temp;
	temp.mSize = this->mSize + str.mSize;
	if (NULL != temp.pAddress)
	{
		delete[] temp.pAddress;
		temp.pAddress = NULL;
	}
	temp.pAddress = new char[temp.mSize + 1];
	strcpy(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, str.pAddress);
	return temp;
}
MyString MyString::operator+(const char *s) //�Ӻ����������
{
	MyString temp;
	temp.mSize = this->mSize + strlen(s);
	if (NULL != temp.pAddress)
	{
		delete[] temp.pAddress;
		temp.pAddress = NULL;
	}
	temp.pAddress = new char[temp.mSize + 1];
	strcpy(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, s);
	return temp;
}

MyString& MyString::operator+=(const MyString& str) //�ӵ����������
{
	*this = *this + str;
	return *this;
}
MyString& MyString::operator+=(const char *s) //�ӵ����������
{
	*this = *this + s;
	return *this;
}

char& MyString::operator[](int index) //�±����������
{
	return this->pAddress[index];
}
int MyString::Size() //�����ַ�������
{
	return this->mSize;
}
std::ostream& operator<<(std::ostream &out, MyString &str) //������������
{
	out << str.pAddress << endl;
	return out;
}
std::istream& operator >> (std::istream &in, MyString &str) //�������������
{
	char *buf = new char[1024];
	in >> buf;
	str.mSize = strlen(buf);
	if (NULL != str.pAddress)
	{
		delete[] str.pAddress;
		str.pAddress = NULL;
	}
	str.pAddress = new char[str.mSize + 1];
	strcpy(str.pAddress, buf);
	delete[] buf;
	return in;
}
