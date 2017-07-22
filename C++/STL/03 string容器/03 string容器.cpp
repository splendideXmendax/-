#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化
*/

//1. 字符串初始化
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
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/

//2. string赋值操作
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
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
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

	//s[i]如果越界，直接终止程序
	//s.at(i) 如果越界会抛出异常
	try
	{
		//s[100] = 100;
		s.at(100) = 100;

	}
	catch (exception &ex)
	{
		//cout << ex.what() << endl;
		cout << "数组下标越界！" << endl;
	}

}

/*
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c
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
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

*/

//5. 查找替换
void test05()
{
	
	string s = "hello worlld!";
	int pos = s.find("ll0");
	//pos = s.rfind("ll");
	cout << "pos = " << pos << endl;

	//如果查找成功返回字符串第一次出现的位置(从0开始)
	//如果查找失败，返回-1



	s.replace(1, 3, "ppp");
	cout << "s = " << s << endl;
}

//6.比较操作
/*
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
*/
void test06()
{

	string s1 = "aaa";
	string s2 = "bbb";

	if (s1 == s2)
	{
		cout << "相等!" << endl;
	}

	if (s1 != s2)
	{
		cout << "不相等!" << endl;
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
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
*/

//7. 截取子串
void test07()
{
	string s = "aaabbcccddd";
	string ret = s.substr(3, 2);
	cout << "ret = " << ret << endl;


	//cout << string::npos << endl;
}

//8. 插入删除
/*
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
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

//9. string和C_style字符串互相转换
void test09()
{

	//const char * -> string
	const char *p = "hello world!";
	string s(p);

	//string -> const char *
	const char *pp = s.c_str();

}

//注意引用失效
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