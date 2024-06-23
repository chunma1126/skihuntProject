#include <windows.h>
#include "consoleHeader.h"

void FullScreen() {
	/*SetConsoleDisplayMode
	(GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE, NULL);*/

	/*ShowWindow(GetConsoleWindow(),
		SW_MAXIMIZE);*/

	::SendMessage(GetConsoleWindow(),
		WM_SYSKEYDOWN,
		VK_RETURN, 0x2000000);
}
void GotoXY(int x, int y) {
	//콘솔창 핸들
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//커서관련 구조체
	COORD CUR = { x *2,y };
	//커서포지션 세팅
	SetConsoleCursorPosition(hOut, CUR);
}

COORD CursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&buf);
	return buf.dwCursorPosition;
}

void CursorVis(bool _vis, DWORD _size)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = _size;//커서굵기 1~100
	curInfo.bVisible = _vis;//on, off
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&curInfo);
}

void SetColor(int _textColor, int _bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		(_bgColor << 4) | _textColor);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&info);
	int color = info.wAttributes & 0xf;
	return color;
}

BOOL GotoPos(int x, int y)
{
	//콘솔창 핸들
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//커서관련 구조체
	COORD CUR = { x * 2,y };
	//커서포지션 세팅
	return SetConsoleCursorPosition(hOut, CUR);
}

void LockResize()
{
	HWND console = GetConsoleWindow();
	if (nullptr != console) {
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;// &~WS_CAPTION;
		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&info);
	short width = info.srWindow.Right - info.srWindow.Left +1;
	short height = info.srWindow.Bottom - info.srWindow.Top +1;
	return COORD{ width, height };
}

void SetFontSize(UINT _weight, UINT _fontx, UINT _fonty)
{
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hout, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _fontx;
	font.dwFontSize.Y = _fonty;
	SetCurrentConsoleFontEx(hout, false, &font);
}
