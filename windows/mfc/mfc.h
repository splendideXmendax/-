#include <afxwin.h> //mfc 必须的头文件  af全局的意思

//1 创建应用程序类 

class MyApp :public CWinApp
{
public:
	//虚函数, 应用程序入口
	virtual BOOL InitInstance();

};

//2 创建框架(窗口)类
class MyFrame :public CFrameWnd
{
public:
	//构造函数， 创建窗口
	MyFrame();

	//1..声明将在一个类中使用消息机制，把消息映射到函数（必须用在类声明中）
	DECLARE_MESSAGE_MAP()  //建立一种关联  --- 消息映射 

	//3.声明消息映射函数
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT, UINT, UINT);


};


