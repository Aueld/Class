/*
	API : application program interface

	메세지
	- 윈도우에서 발생하는 모든 이벤트

	메세지 큐
	- 메세지들은 매크로 상수로 변환되어서 메세지 큐에 저장

	메세지 루프
	- 메세지를 알맞은 형태로 변환

	윈도우 프로시저
	- 사전에 정의된 내용에 맞게 처리하는 함수, gdi
*/

/*
	LPSTR		= long pointer str = char*
	LPCSTR		= const char*
	LPWSTR		= wchar_t*
	LPCWSTR		= const wchar_t* 	
*/

#include <Windows.h>
#include <cassert>
#include <string>

LRESULT CALLBACK WndProc
(
	HWND handle,	// 핸들
	UINT message,	// 메시지
	WPARAM wParam,	// 이벤트 처리
	LPARAM lParam
);
// callback 운영체제에 의해 호출되는 함수, stdCall 함수 호출 규약 win32 API 함수 호출하는데 사용


int APIENTRY WinMain
(
	HINSTANCE hInstance,
	HINSTANCE prevInstance,
	LPSTR lpszCmdParam,
	int nCmdShow
)
{
	WNDCLASSA wnd_class;	// 설명창

	wnd_class.cbClsExtra = 0;	// 클래스 확장 공간 사용 여부
	wnd_class.cbWndExtra = 0;	// 내부 확장 공간 사용 여부
	wnd_class.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));	// 윈도우 창 색 지정

	wnd_class.hCursor = LoadCursor(nullptr, IDC_CROSS);	// 커서 모양 설정
	wnd_class.hIcon = LoadIcon(nullptr, IDI_ERROR);		// 작업 표시줄 모양
	wnd_class.hInstance = hInstance;

	wnd_class.lpfnWndProc = WndProc;
	wnd_class.lpszClassName = "Window";	// 이름
	wnd_class.lpszMenuName = nullptr;	// 메뉴바 이름
	wnd_class.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassA(&wnd_class);


	HWND hwnd = CreateWindowA
	(
		"Window",	// 불러올 윈도우 이름
		"Hello",
		WS_OVERLAPPEDWINDOW,
		0, 0,
		800, 600,	// 윈도우 창 크기
		nullptr,	// 부모창
		nullptr,	// 메뉴
		hInstance,	// hInstance
		nullptr		// 부가적인 정보
	);

	assert(hwnd != nullptr);

	ShowWindow(hwnd, nCmdShow);
	ShowCursor(TRUE);

	MSG message;
	ZeroMemory(&message, sizeof(MSG));	// 안전한 초기화

	// 화면 실행
	while (GetMessage(&message, nullptr, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	DestroyWindow(hwnd);
	UnregisterClassA("Window", hInstance);
}

LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
#pragma region Message Box
	//case WM_LBUTTONDOWN:
	//	MessageBoxA(nullptr, "Hello", "ERROR", MB_OKCANCEL);
	//	break;
#pragma endregion
#pragma region Text
	//case WM_KEYDOWN:
	//{
	//	std::string str = "Mouse Clicked";
	//	HDC hdc = GetDC(handle);	// handle device context
	//	
	//	TextOutA(hdc, 500, 300, str.c_str(), str.length());

	//	ReleaseDC(handle, hdc);

	//	break;
	//}

	//case WM_PAINT:
	//{
	//	std::string str = "WM_PAINT message occurred";

	//	PAINTSTRUCT ps;

	//	HDC hdc = BeginPaint(handle, &ps);

	//	TextOutA(hdc, 500, 200, str.c_str(), str.length());

	//	EndPaint(handle, &ps);

	//	break;
	//}
#pragma endregion
		static POINT position;
#pragma region TextMoving
	//case WM_KEYDOWN:
	//{
	//	if (wParam == VK_UP)
	//	{
	//		position.y -= 10;
	//	}
	//	else if (wParam == VK_DOWN)
	//	{
	//		position.y += 10;
	//	}
	//	else if (wParam == VK_LEFT)
	//	{
	//		position.x -= 10;
	//	}
	//	else if (wParam == VK_RIGHT)
	//	{
	//		position.x += 10;
	//	}

	//	InvalidateRect(handle, nullptr, TRUE);	// 화면 갱신
	//	break;
	//}
	//case WM_PAINT:
	//{
	//	PAINTSTRUCT ps;
	//	HDC hdc = BeginPaint(handle, &ps);
	//	TextOutA(hdc, position.x, position.y, "ㅁ", 2);
	//	EndPaint(handle, &ps);
	//	break;
	//}
#pragma endregion
#pragma region MouseMove
	case WM_MOUSEMOVE:
		position.x = LOWORD(lParam);
		position.y = HIWORD(lParam);

		InvalidateRect(handle, nullptr, TRUE);
		break;
	case WM_PAINT:
	{
		std::string str = "";
		str += std::to_string(position.x);
		str += ", ";
		str += std::to_string(position.y);

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(handle, &ps);
		TextOutA(hdc, position.x, position.y, str.c_str(), str.length());
		
		MoveToEx(hdc, 100, 100, nullptr);

		LineTo(hdc, 500, 500);

		Rectangle(hdc, 500, 500, 600, 600);
		Ellipse(hdc, 300, 300, 400, 500);
		
		EndPaint(handle, &ps);

		break;
	}
#pragma endregion
	case WM_CLOSE:		// 윈도우 종료시
	case WM_DESTROY:	// 윈도우 종료시
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProcA(handle, message, wParam, lParam);	// 처리되지 않은 메시지 처리
		break;
	}

	return 0;
}
