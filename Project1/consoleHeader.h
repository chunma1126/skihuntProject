#pragma once
#include <Windows.h>
void FullScreen();
void GotoXY(int x, int y);
BOOL GotoPos(int x, int y);
COORD CursorPos();
void CursorVis(bool _vis, DWORD _size);
void SetColor(int _textColor = 15, int _bgColor=0);
int GetColor();
void LockResize();
COORD GetConsoleResolution();
void SetFontSize(UINT _weight, UINT _fontx, UINT _fonty);

enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};