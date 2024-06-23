#pragma once
#include<iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <chrono>
using std::cout;
using std::wcout;
using std::vector;
using std::endl;

const int MAP_WIDTH = 52;
const int MAP_HEIGHT = 36;

typedef struct tagPos {
	int x;
	int y;
	bool operator ==(const tagPos& _pos) {
		if (x == _pos.x && y == _pos.y)
			return true;
		else
			return false;
	}
}POS, * PPOS;

typedef struct tagPlayer {
	POS tPos;
	POS newPos;
	int hp;
	bool canShot;
}PLAYER, * PPLAYER;

typedef struct tagAim {
	POS tPos;
	POS newPos;
}AIM, * PAIM;

typedef struct tagBullet {
	POS tPos;
	POS newPos;
}BULL, * PBULL;

enum class OBJ_TYPE {
	NILL = '0', WALL, START, TREE,
	ANIMAL, DOWN
};


void Init(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PAIM _pAim, PBULL _pBullet, PPOS _pStartPos);
void ShotBullet(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER player, PAIM aim, PBULL bullet);
void Render(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PAIM _pAim, PBULL _pBullet);
void Update(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PAIM _pAim, PBULL _pBullet);
void Move(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PAIM _pAim, PBULL _pBullet);
void FrameSync(unsigned int _Framerate);
