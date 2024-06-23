#include<iostream>
#include<fcntl.h>
#include<io.h>
#include<Windows.h>
#include "TitleScene.h"
#include "consoleHeader.h"
#include "Jung.h"
using namespace std;

void TitleRender()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"   ▄████████    ▄█   ▄█▄  ▄█         ▄█    █▄    ███    █▄  ███▄▄▄▄       ███      " << endl;
	wcout << L"  ███    ███   ███ ▄███▀ ███        ███    ███   ███    ███ ███▀▀▀██▄ ▀█████████▄  " << endl;
	wcout << L"  ███    █▀    ███▐██▀   ███▌       ███    ███   ███    ███ ███   ███    ▀███▀▀██  " << endl;
	wcout << L"  ███         ▄█████▀    ███▌      ▄███▄▄▄▄███▄▄ ███    ███ ███   ███     ███   ▀  " << endl;
	wcout << L"▀███████████ ▀▀█████▄    ███▌     ▀▀███▀▀▀▀███▀  ███    ███ ███   ███     ███      " << endl;
	wcout << L"         ███   ███▐██▄   ███        ███    ███   ███    ███ ███   ███     ███      " << endl;
	wcout << L"   ▄█    ███   ███ ▀███▄ ███        ███    ███   ███    ███ ███   ███     ███      " << endl;
	wcout << L" ▄████████▀    ███   ▀█▀ █▀         ███    █▀    ████████▀   ▀█   █▀     ▄████▀    " << endl; 

	int curmode = _setmode(_fileno(stdout), prevmode);
	GotoXY(0, 0);
}

bool Title()
{
	while (true)
	{
		TitleRender();
		MENU eMenu = MenuRender();
		switch (eMenu)
		{
		case MENU::START:
			EnterAnimation();
			return true;
		case MENU::INFO:
			InfoRender();
			break;
		case MENU::QUIT:
			return false;
		}
	}

}

MENU MenuRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 4.5;
	int y = Resolution.Y / 2.5;
	int originy = y;
	GotoXY(x, y);
	cout << "게임 시작";
	GotoXY(x, y + 1);
	cout << "게임 정보";
	GotoXY(x, y + 2);
	cout << "종료 하기";
	while (true)
	{
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
		{
			if (y > originy)
			{
				GotoXY(x - 2, y);
				cout << " ";
				GotoXY(x - 2, --y);
				cout << ">";
				Sleep(100);
			}
		}
		break;
		case KEY::DOWN:
		{
			if (y < originy + 2)
			{
				GotoXY(x - 2, y);
				cout << " ";
				GotoXY(x - 2, ++y);
				cout << ">";
				Sleep(100);
			}
		}
		break;
		case KEY::SPACE:
			if (originy == y)
				return MENU::START;
			else if (originy + 1 == y)
				return MENU::INFO;
			else if (originy + 2 == y)
				return MENU::QUIT;
		}
	}
}

void InfoRender()
{
	cout << "[조작법]" << endl;
	cout << "[게임 플레이 방법]" << endl;
	while (true)
	{
		if (KeyController() == KEY::SPACE)
			break;
	}
}

KEY KeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		return KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		return KEY::SPACE;
	}

	return KEY::FAIL;
}

void EnterAnimation()
{
	COORD Resolution = GetConsoleResolution();
	int width = Resolution.X;
	int height = Resolution.Y;
	int animtime = 20;

	// 5번 깜빡거리기.
	for (int i = 0; i < 5; ++i)
	{
		GotoXY(0, 0);
		SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
		system("cls");
		
		Sleep(animtime);

		GotoXY(0, 0);
		SetColor((int)COLOR::WHITE);
		system("cls");
		
		Sleep(animtime);
	}
}
