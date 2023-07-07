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
	static POINT position;
	static POINT start;
	static POINT end;
	static bool is_clicked;

	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		start.x = LOWORD(lParam);
		start.y = HIWORD(lParam);

		is_clicked = TRUE;

		break;
	}
	case WM_MOUSEMOVE:
	{
		if (is_clicked)
		{
			HDC hdc = GetDC(handle);

			MoveToEx(hdc, position.x, position.y, nullptr);

			end.x = LOWORD(lParam);
			end.y = HIWORD(lParam);

			InvalidateRect(handle, nullptr, TRUE);

			//LineTo(hdc, position.x, position.y);
			//ReleaseDC(handle, hdc);
		}

		break;
	}
	case WM_LBUTTONUP:
	{
		is_clicked = false;

		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(handle, &ps);

		HPEN cur_pen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		HPEN old_pen = static_cast<HPEN>(SelectObject(hdc, cur_pen));

		//HBRUSH cur_brush = CreateSolidBrush(RGB(0, 255, 255));
		HBRUSH cur_brush = CreateHatchBrush(PS_DOT, RGB(0, 0, 255));
		HBRUSH old_brush = static_cast<HBRUSH>(SelectObject(hdc, cur_brush));

		Rectangle(hdc, start.x, start.y, end.x, end.y);

		SelectObject(hdc, old_pen);
		DeleteObject(cur_pen);

		SelectObject(hdc, old_brush);
		DeleteObject(cur_brush);

		EndPaint(handle, &ps);

		break;
	}
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
