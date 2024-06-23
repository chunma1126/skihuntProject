#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <mmsystem.h>
#include <thread>
#include <cmath>
#include <chrono>
#include <cmath>
#pragma comment(lib,"winmm.lib")
#include "GameSystem.h"
#include "consoleHeader.h"


void Init(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PAIM _pAim, PBULL _pBullet ,PPOS _pStartPos)
{
	system("title BOMBerMAN | mode con cols=104 lines=52");
	CursorVis(false, 1);
	LockResize();
	//PlayBgm(TEXT("ant.wav"), 100);
	SetFontSize(FW_BOLD, 20, 20);

	strcpy_s(_arrMap[0], "11111111111111111111111111111111111111111111111111");
	strcpy_s(_arrMap[1], "10000000000000000020000000000000000000000000000001");
	strcpy_s(_arrMap[2], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[3], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[4], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[5], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[6], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[7], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[8], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[9], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[10], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[11], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[12], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[13], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[14], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[15], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[16], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[17], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[18], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[19], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[20], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[21], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[22], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[23], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[24], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[25], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[26], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[27], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[28], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[29], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[30], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[31], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[32], "10000000000000000000000000000000000000000000000001");
	strcpy_s(_arrMap[33], "15555555555555555555555555555555555555555555555551");
	strcpy_s(_arrMap[34], "11111111111111111111111111111111111111111111111111");

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (_arrMap[i][j] == (char)OBJ_TYPE::START) {
				*_pStartPos = { j, i };
			}
		}
	}
	*_pPlayer = { *_pStartPos,{},100,false };
	*_pAim = { *_pStartPos,{} };
	*_pBullet = { 999,999 };
}

void ShotBullet(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER player, PAIM aim, PBULL bullet) {

	// 방향
	int dx = aim->tPos.x - player->tPos.x;
	int dy = aim->tPos.y - player->tPos.y;

	int steps = max(abs(dx), abs(dy));
	float xIncrement = dx / static_cast<float>(steps);
	float yIncrement = dy / static_cast<float>(steps);

	int x = player->tPos.x;
	int y = player->tPos.y;

	bullet->newPos = { x,y };
	for (int i = 0; i <= steps; ++i) {
		bullet->newPos.y = y;
		bullet->newPos.x = x;
		bullet->tPos.x = std::clamp(bullet->newPos.x, 0, MAP_WIDTH - 2);
		bullet->tPos.y = std::clamp(bullet->newPos.x, 0, MAP_WIDTH - 2);
		Render(_arrMap, player, aim, bullet);
		GotoXY(0, 0);
		std::this_thread::sleep_for(std::chrono::nanoseconds(1));
		x += xIncrement;
		y += yIncrement;
	}

}

void Render(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PAIM _pAim, PBULL _pBullet)
{
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {

			if (_pPlayer->tPos.x == j && _pPlayer->tPos.y == i) {
				cout << "＆";
			}
			else if (_pAim->tPos.x == j && _pAim->tPos.y == i) {
				cout << "▦";
			}
			else if (_pBullet->tPos.x == j && _pBullet->tPos.y == i) {
				cout << "＊";
			}
			else if (_arrMap[i][j] == (char)OBJ_TYPE::NILL) {
				cout << "  ";
			}
			else if (_arrMap[i][j] == (char)OBJ_TYPE::WALL) {
				cout << "■";
			}
			else if (_arrMap[i][j] == (char)OBJ_TYPE::START) {
				cout << "  ";
			}
			else if (_arrMap[i][j] == (char)OBJ_TYPE::TREE) {
				cout << "♣";
			}
			else if (_arrMap[i][j] == (char)OBJ_TYPE::ANIMAL) {
				cout << "♨";
			}
			
			else if (_arrMap[i][j] == (char)OBJ_TYPE::DOWN) {
				cout << "  ";
			}
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		}
		cout << endl;
	}
}

void Update(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PAIM _pAim, PBULL _pBullet)
{
	Move(_arrMap, _pPlayer, _pAim, _pBullet);
}

void Move(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PAIM _pAim, PBULL _pBullet)
{
	//player
	_pPlayer->newPos = _pPlayer->tPos;
	if (GetAsyncKeyState('W') & 0x8000)
		--_pPlayer->newPos.y;
	if (GetAsyncKeyState('S') & 0x8000)
		++_pPlayer->newPos.y;
	if (GetAsyncKeyState('D') & 0x8000)
		++_pPlayer->newPos.x;
	if (GetAsyncKeyState('A') & 0x8000)
		--_pPlayer->newPos.x;

	_pPlayer->tPos.x = std::clamp(_pPlayer->newPos.x, 0, MAP_WIDTH - 2);
	_pPlayer->tPos.y = std::clamp(_pPlayer->newPos.x, 0, MAP_WIDTH - 2);


	if (_arrMap[_pPlayer->newPos.y][_pPlayer->newPos.x]
		!= (char)OBJ_TYPE::WALL)
		_pPlayer->tPos = _pPlayer->newPos;

	//aim
	_pAim->newPos = _pAim->tPos;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		--_pAim->newPos.y;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		++_pAim->newPos.y;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++_pAim->newPos.x;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--_pAim->newPos.x;

	_pAim->tPos.x = std::clamp(_pAim->newPos.x, 0, MAP_WIDTH - 2);
	_pAim->tPos.y = std::clamp(_pAim->newPos.x, 0, MAP_WIDTH - 2);

	_pAim->tPos = _pAim->newPos;
	/*if (_arrMap[_pAim->newPos.y][_pAim->newPos.x]
		!= (char)OBJ_TYPE::WALL)
		_pAim->tPos = _pAim->newPos;*/

	//발사
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		ShotBullet(_arrMap, _pPlayer, _pAim, _pBullet);
}

void FrameSync(unsigned int _Framerate)
{
	clock_t oldtime = clock();
	clock_t curtime;
	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 1000 / _Framerate) {
			oldtime = curtime;
			break;
		}
	}
}


