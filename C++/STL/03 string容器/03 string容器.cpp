#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
string();//����һ���յ��ַ��� ����: string str;
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
string(const char* s);//ʹ���ַ���s��ʼ��
string(int n, char c);//ʹ��n���ַ�c��ʼ��
*/

//1. �ַ�����ʼ��
void test01()
{
	string s;
	string s2 = "hello world!";
	string s3(10, 'a');

	int len = s2.size();
	for (int i = 0; i < len; ++i)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	for (string::iterator it = s2.begin(); it != s2.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

}

/*
string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);//���ַ���s������ǰ���ַ���
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
string& assign(const char *s);//���ַ���s������ǰ���ַ���
string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);//���ַ���s������ǰ�ַ���
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
*/

//2. string��ֵ����
void test02()
{
	string s;
	string s2 = "qwerty";
	s = "hello world!";
	cout << "s = " << s << endl;

	s = s2;
	cout << "s = " << s << endl;


	s = 'a'; 
	cout << "s = " << s << endl;

	s.assign("qwer",2);
	cout << "s = " << s << endl;

	s.assign(s2, 2, 3);
	cout << "s = " << s << endl;

}


/*
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�
*/

void test03()
{

	string s = "hello world!";

	for (int i = 0; i < s.size(); ++i)
	{
		//cout << s[i] << " ";
		cout << s.at(i) << " ";
	}
	cout << endl;

	//s[i]���Խ�磬ֱ����ֹ����
	//s.at(i) ���Խ����׳��쳣
	try
	{
		//s[100] = 100;
		s.at(100) = 100;

	}
	catch (exception &ex)
	{
		//cout << ex.what() << endl;
		cout << "�����±�Խ�磡" << endl;
	}

}

/*
string& operator+=(const string& str);//����+=������
string& operator+=(const char* str);//����+=������
string& operator+=(const char c);//����+=������
string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string &s);//ͬoperator+=()
string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c
*/
void test04()
{
	string s = "aaa";
	s += "bbb";
	cout << "s = " << s << endl;
	string s2 = "ccc";
	s += s2;
	cout << "s = " << s << endl;
	s.append(5, 'd');
	cout << "s = " << s << endl;

}

/*
int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

*/

//5. �����滻
void test05()
{
	
	string s = "hello worlld!";
	int pos = s.find("ll0");
	//pos = s.rfind("ll");
	cout << "pos = " << pos << endl;

	//������ҳɹ������ַ�����һ�γ��ֵ�λ��(��0��ʼ)
	//�������ʧ�ܣ�����-1



	s.replace(1, 3, "ppp");
	cout << "s = " << s << endl;
}

//6.�Ƚϲ���
/*
compare������>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС��
��д��A��Сд��aС��
int compare(const string &s) const;//���ַ���s�Ƚ�
int compare(const char *s) const;//���ַ���s�Ƚ�
*/
void test06()
{

	string s1 = "aaa";
	string s2 = "bbb";

	if (s1 == s2)
	{
		cout << "���!" << endl;
	}

	if (s1 != s2)
	{
		cout << "�����!" << endl;
	}

	if (s1 < s2)
	{
		cout << "s1 < s2!" << endl;
	}

	if (s1 > s2)
	{
		cout << "s1 > s2!" << endl;
	}

	if (s1.compare(s2) == -1)
	{
		cout << "s1 < s2!" << endl;
	}

	if (s1.compare(s2) == 0)
	{
		cout << "s1 = s2!" << endl;
	}

	if (s1.compare(s2) == 1)
	{
		cout << "s1 > s2!" << endl;
	}
}


/*
string substr(int pos = 0, int n = npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���
*/

//7. ��ȡ�Ӵ�
void test07()
{
	string s = "aaabbcccddd";
	string ret = s.substr(3, 2);
	cout << "ret = " << ret << endl;


	//cout << string::npos << endl;
}

//8. ����ɾ��
/*
string& insert(int pos, const char* s); //�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ�
*/

void test08()
{
	
	string s = "aaabbccc";
	s.insert(3, "OOOOO");
	s.insert(0, 3, 'Q');

	cout << "s = " << s << endl;

	s.erase(0, 3);
	cout << "s = " << s << endl;
}

//9. string��C_style�ַ�������ת��
void test09()
{

	//const char * -> string
	const char *p = "hello world!";
	string s(p);

	//string -> const char *
	const char *pp = s.c_str();

}

//ע������ʧЧ
void test10()
{
	string s = "aaaa";
	cout << (int)&s[0] << endl;

	char &ref = s[0];

	s += "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	cout << (int)&s[0] << endl;

	ref = 'p';
}

int main(){


	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	test10();


	system("pause");
	return EXIT_SUCCESS;
}