#include <afxwin.h> //mfc �����ͷ�ļ�  afȫ�ֵ���˼

//1 ����Ӧ�ó����� 

class MyApp :public CWinApp
{
public:
	//�麯��, Ӧ�ó������
	virtual BOOL InitInstance();

};

//2 �������(����)��
class MyFrame :public CFrameWnd
{
public:
	//���캯���� ��������
	MyFrame();

	//1..��������һ������ʹ����Ϣ���ƣ�����Ϣӳ�䵽���������������������У�
	DECLARE_MESSAGE_MAP()  //����һ�ֹ���  --- ��Ϣӳ�� 

	//3.������Ϣӳ�亯��
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT, UINT, UINT);


};


