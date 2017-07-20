#include <windows.h>

//int main(int argc, char* argv[])

//6.���ڹ��̺���
LRESULT CALLBACK WinProc(
	HWND hwnd, //��Ϣ���ڵĴ���
	UINT uMsg, //��ȡ������Ϣ
	WPARAM wParam, //������Ϣ ������Ϣ
	LPARAM lParam  //������Ϣ�� �����Ϣ
	)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);	//������ϢWM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(1);		//�˳�
		break;
	case WM_LBUTTONDOWN: //���������
	{//int MessageBox(HWND hwnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);

		//int x = LOWORD(lParam);  //��ȡ�����������
		//int y = HIWORD(lParam);
		int x = LOWORD(lParam);  //��ȡ�����������
		int y = HIWORD(lParam);


		char *buf[64] = { 0 };
		wsprintf(buf, TEXT("x=%d, y=%d"), x, y);
		MessageBox(hwnd, buf, TEXT("info"), MB_OK);
	}
		break;
	case WM_KEYDOWN:
		MessageBox(hwnd, TEXT("WM_LBUTTONDOWN"), TEXT("info"), MB_OK);
		break;
	case WM_PAINT:		//������Ϣ����û�д���Ĳ������׳����� �ǳ�����Դ
	{
		PAINTSTRUCT pPaint;
	 	HDC hdc = BeginPaint(hwnd, &pPaint);
		TextOut(hdc, 100, 300, TEXT("hello"), 5); //��ͼ
		EndPaint(hwnd, &pPaint);
	}
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}


	return 0;
}


//��ں��� WinMain
//WINAPI ���� ����������ջ�� �������� ���Ӧջ
int WINAPI WinMain(
	HINSTANCE hInstance, //Ӧ�ó���ʵ�� �����е�
	HINSTANCE hPrevInstance,//Ӧ�ó���ʵǰһ��ʵ�� ΪNULL
	LPSTR lpCmdLine,	//�����б��൱�� argv, ����cha*
	int nCmdShow	//��� Ĭ��Ϊ0
	)
{
	//��������
	//1 ��ƴ��� 
	WNDCLASS ws; //�����࣬�������ڶ���
	ws.cbClsExtra = 0; // �����ռ䣬 ͨ�� ��Ϊ0
	ws.cbWndExtra = 0; // ���ڶ���ռ䣬 ͨ����Ϊ0
	ws.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���ñ���ɫ
	ws.hCursor = LoadCursor(NULL, IDC_CROSS); // ���ù�꣬��һ������ΪNULL����ϵͳ�ṩ�ı�׼���
	ws.hIcon = LoadIcon(NULL, IDI_ERROR); //����ͼ�꣬ ��һ������ΪNULL����ϵͳ�ṩ�ı�׼ͼ��
	ws.hInstance = hInstance; // Ӧ�ó���ʵ����� winMain������һ������
	ws.lpfnWndProc = WinProc; // ���ڹ��̺���
	ws.lpszClassName = TEXT("win"); // ��������
	ws.lpszMenuName = NULL; // ��ΪNULL�� û�в˵���
	ws.style = 0; //��� Ĭ��Ϊ0

	//2 ע�ᴰ�� 
	RegisterClass(&ws);
	//3 ��������
	HWND hWnd = CreateWindow(  //���ص���һ�����ھ��
		//		LPCTSTR lpClassName,  
		TEXT("win"), //��������
		//		LPCTSTR lpWindowName,	
		TEXT("winTest"),//���ڱ���
		//	DWORD dwStyle,     //���
		WS_OVERLAPPEDWINDOW, // ��� WS_OVERLAPPEDWINDOW ��Ϸ��
		//	int x,��������
		//	int y,
		200, 300,
		//	int nWidth,���ڴ�С
		//	int nHeight,
		1000, 600,
		//	HWND hWndParent, ������ û�� ��ΪNULL
		NULL,
		//	HMENU hMenu, �˵���  û�� ��ΪNULL
		NULL,
		//	HINSTANCE hInstance, Ӧ�ó���ʵ�����
		hInstance,
		//  LPVOID lpParam ������Ϣ û�л���NULL
		NULL
		);

	//4 ��ʾ�͸��´���
	ShowWindow(hWnd, SW_SHOWNORMAL); //(����� ��ʾģʽ)
	UpdateWindow(hWnd); //����

//---------------------------------------------------------------
	//5 ��Ϣѭ��
	MSG msg;
	while (1)
	{
		//��ȡ��Ϣ ��ȡ��WM_QUIT ʱ �˳�Ӧ�ó���
	//	BOOL  GetMessage(LPMSG lpMsg,
	//		HWND hWnd,
	//		UINT wMsgFilterMin,
	//		UINT );
		BOOL ret = GetMessage(
			&msg, // ��ȡ������Ϣ
			NULL, //��Ϣ���ڵĴ��ڣ� ��ΪNULL��ȡ���д��ڵ���Ϣ
			0, 0 //��Ϊ0 ��ȡ������Ϣ
			);
		if (FALSE == ret)
		{
			break;
		}

		//��Ϣ���� PS ��Щ��Ϣ�Ƚ��ر���簴��app��ȡ��Ϣ֮�󲢲�֪������Ϣ�ľ��������
					//��ô���ͷ���һ����Ϣ���� ���� ���� �Ͱ���λ�� �����²�����Ϣ����
		TranslateMessage(&msg);
		//

		//�ַ���Ϣ
		DispatchMessage(&msg);

	}
	return 0;
}