#include "mfc.h"

MyApp myApp; // Ӧ�ó����������ֻ��һ����ȫ��
//Ӧ�ó������
BOOL MyApp::InitInstance() //���� ---> ���� ---> MFC��ʹ�� ---> �ڹ���DLL��ʹ��MFC �����ʹ��MFC�����
						   //ȫ�ֱ���
{
	//1 ��������
	MyFrame *frame = new MyFrame;

	//2 ��ʾ�͸��´���
	//�����ĵ���Ҫ������   CWnd::ShowWindow(SW_SHOWNORMAL)
	//�����ĵ���Ҫ������   CWnd::UpdateWindow()
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	//3 ����ָ��Ӧ�ó������Ҫ���ڵ�ָ��
	//CWnd
	m_pMainWnd = frame;


	return TRUE;
}

//2.������Ϣӳ����� //һ����ӿؼ����Զ���ӵ�
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_CHAR()
END_MESSAGE_MAP()

//���캯��
MyFrame::MyFrame()
{
	//��������
	//CFrameWnd::Crete
	Create(NULL, TEXT("mfctest"));
}
//4.ʵ����Ϣӳ�亯��
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

	//MFC���������ַ���  ���ֽ��ַ��� unicode�ַ���
	//���ֽھ���ASIIC��  ��Ϊ   unicode  GBK

	//L�����ֽ��ַ���ת����unicode�ַ���
//	MessageBox(L"hello");


	//TEXT TCHAR����Ӧ�ַ���
	MessageBox(TEXT("HEEL2"));

	TCHAR *buf = TEXT("hello3"); //�ǳ���ȫ��һһ���÷�

	char *buf2 = "hello4"; //�����ַ��� �������ַ�������
	wchar_t *buf3 = L"hello5";
	int n = strlen(buf2);
	n = wcslen(buf3); //����

	//CString cha*

	//char* ->CString  ת��
	char *buf4 = "hello6";
	//MessageBox(CString(buf4)); //ֱ��ת��

	//CString->char* ת��
	CStringA tmp;
	CStringW tmp2;
	CString str = TEXT("hello7");
	tmp = str;

	char *buf5 = tmp.GetBuffer();
	MessageBox(CString(buf4));




}
