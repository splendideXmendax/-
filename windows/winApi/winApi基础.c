#include <windows.h>

//int main(int argc, char* argv[])

//6.窗口过程函数
LRESULT CALLBACK WinProc(
	HWND hwnd, //消息所在的窗口
	UINT uMsg, //获取到的消息
	WPARAM wParam, //附加信息 键盘信息
	LPARAM lParam  //附加信息， 鼠标信息
	)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);	//产生消息WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(1);		//退出
		break;
	case WM_LBUTTONDOWN: //点击下鼠标后
	{//int MessageBox(HWND hwnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);

		//int x = LOWORD(lParam);  //获取鼠标点击的坐标
		//int y = HIWORD(lParam);
		int x = LOWORD(lParam);  //获取鼠标点击的坐标
		int y = HIWORD(lParam);


		char *buf[64] = { 0 };
		wsprintf(buf, TEXT("x=%d, y=%d"), x, y);
		MessageBox(hwnd, buf, TEXT("info"), MB_OK);
	}
		break;
	case WM_KEYDOWN:
		MessageBox(hwnd, TEXT("WM_LBUTTONDOWN"), TEXT("info"), MB_OK);
		break;
	case WM_PAINT:		//处理消息里面没有处理的操作容易出问题 非常耗资源
	{
		PAINTSTRUCT pPaint;
	 	HDC hdc = BeginPaint(hwnd, &pPaint);
		TextOut(hdc, 100, 300, TEXT("hello"), 5); //绘图
		EndPaint(hwnd, &pPaint);
	}
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}


	return 0;
}


//入口函数 WinMain
//WINAPI 参数 从右往左入栈， 函数结束 清空应栈
int WINAPI WinMain(
	HINSTANCE hInstance, //应用程序实例 ，运行的
	HINSTANCE hPrevInstance,//应用程序实前一个实例 为NULL
	LPSTR lpCmdLine,	//参数列表相当于 argv, 类型cha*
	int nCmdShow	//风格， 默认为0
	)
{
	//创建窗口
	//1 设计窗口 
	WNDCLASS ws; //窗口类，创建窗口对象
	ws.cbClsExtra = 0; // 类额外空间， 通常 设为0
	ws.cbWndExtra = 0; // 窗口额外空间， 通常设为0
	ws.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //设置背景色
	ws.hCursor = LoadCursor(NULL, IDC_CROSS); // 设置光标，第一个参数为NULL采用系统提供的标准光标
	ws.hIcon = LoadIcon(NULL, IDI_ERROR); //设置图标， 第一个参数为NULL采用系统提供的标准图标
	ws.hInstance = hInstance; // 应用程序实例句柄 winMain函数第一个参数
	ws.lpfnWndProc = WinProc; // 窗口过程函数
	ws.lpszClassName = TEXT("win"); // 窗口类名
	ws.lpszMenuName = NULL; // 设为NULL， 没有菜单栏
	ws.style = 0; //风格， 默认为0

	//2 注册窗口 
	RegisterClass(&ws);
	//3 创建窗口
	HWND hWnd = CreateWindow(  //返回的是一个窗口句柄
		//		LPCTSTR lpClassName,  
		TEXT("win"), //窗口类名
		//		LPCTSTR lpWindowName,	
		TEXT("winTest"),//窗口标题
		//	DWORD dwStyle,     //风格
		WS_OVERLAPPEDWINDOW, // 风格， WS_OVERLAPPEDWINDOW 组合风格
		//	int x,窗口坐标
		//	int y,
		200, 300,
		//	int nWidth,窗口大小
		//	int nHeight,
		1000, 600,
		//	HWND hWndParent, 副窗口 没有 设为NULL
		NULL,
		//	HMENU hMenu, 菜单栏  没有 设为NULL
		NULL,
		//	HINSTANCE hInstance, 应用程序实例句柄
		hInstance,
		//  LPVOID lpParam 附加信息 没有还是NULL
		NULL
		);

	//4 显示和更新窗口
	ShowWindow(hWnd, SW_SHOWNORMAL); //(句柄， 显示模式)
	UpdateWindow(hWnd); //更新

//---------------------------------------------------------------
	//5 消息循环
	MSG msg;
	while (1)
	{
		//获取消息 获取到WM_QUIT 时 退出应用程序
	//	BOOL  GetMessage(LPMSG lpMsg,
	//		HWND hWnd,
	//		UINT wMsgFilterMin,
	//		UINT );
		BOOL ret = GetMessage(
			&msg, // 获取到的消息
			NULL, //消息所在的窗口， 设为NULL获取所有窗口的消息
			0, 0 //设为0 获取所有消息
			);
		if (FALSE == ret)
		{
			break;
		}

		//消息翻译 PS 有些消息比较特别比如按键app获取消息之后并不知道是消息的具体的内容
					//那么他就翻译一下消息内容 比如 按键 和按键位置 在重新插入消息队列
		TranslateMessage(&msg);
		//

		//分发消息
		DispatchMessage(&msg);

	}
	return 0;
}