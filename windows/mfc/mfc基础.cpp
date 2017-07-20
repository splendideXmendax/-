#include "mfc.h"

MyApp myApp; // 应用程序对象，有且只有一个，全局
//应用程序入口
BOOL MyApp::InitInstance() //属性 ---> 常规 ---> MFC的使用 ---> 在共享DLL中使用MFC 这就是使用MFC框架了
						   //全局变量
{
	//1 创建窗口
	MyFrame *frame = new MyFrame;

	//2 显示和更新窗口
	//查找文档需要加类名   CWnd::ShowWindow(SW_SHOWNORMAL)
	//查找文档需要加类名   CWnd::UpdateWindow()
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	//3 保存指向应用程序的主要窗口的指针
	//CWnd
	m_pMainWnd = frame;


	return TRUE;
}

//2.定义消息映射入口 //一般添加控件是自动添加的
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_CHAR()
END_MESSAGE_MAP()

//构造函数
MyFrame::MyFrame()
{
	//创建窗口
	//CFrameWnd::Crete
	Create(NULL, TEXT("mfctest"));
}
//4.实现消息映射函数
void MyFrame::OnLButtonDown(UINT, CPoint)
{
	MessageBox(TEXT("OnLButtonDown"));
}
void MyFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.TextOutW(200, 100, TEXT("OnPaint"));
}
void MyFrame::OnChar(UINT key, UINT, UINT)
{
	TCHAR ch = (TCHAR)key;

	//MessageBox(CString(ch));

	//MFC存在两种字符集  多字节字符集 unicode字符集
	//多字节就是ASIIC码  因为   unicode  GBK

	//L将多字节字符集转换成unicode字符集
//	MessageBox(L"hello");


	//TEXT TCHAR自适应字符集
	MessageBox(TEXT("HEEL2"));

	TCHAR *buf = TEXT("hello3"); //非常安全的一一种用法

	char *buf2 = "hello4"; //两种字符集 和两种字符集长度
	wchar_t *buf3 = L"hello5";
	int n = strlen(buf2);
	n = wcslen(buf3); //长度

	//CString cha*

	//char* ->CString  转换
	char *buf4 = "hello6";
	//MessageBox(CString(buf4)); //直接转换

	//CString->char* 转换
	CStringA tmp;
	CStringW tmp2;
	CString str = TEXT("hello7");
	tmp = str;

	char *buf5 = tmp.GetBuffer();
	MessageBox(CString(buf4));




}
