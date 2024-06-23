#include <iostream>
#include "Jung.h"
#include "consoleHeader.h"

enum OBJ_TYPE
{
	MAP = '0',
	TREE,
	ANIMAL,
};

void TreeGeneration(char map[MAP_HEIGHT][MAP_WIDTH])
{
	int random = rand() % (MAP_WIDTH - 1);

	for (int i = 0; i < 3; i++)
	{
		if (MAP_HEIGHT - i - 1 >= 0) {
			map[MAP_HEIGHT - i - 1][random] = (char)OBJ_TYPE::TREE;
		}
	}
	
}

void Render(char map[MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (map[i][j] == (char)OBJ_TYPE::MAP) 
			{
				SetColor((int)COLOR::WHITE);
				std::cout << "  ";
				SetColor((int)COLOR::WHITE);
			}
			else if (map[i][j] == (char)OBJ_TYPE::TREE)
			{
				SetColor((int)COLOR::BLUE);
				std::cout << "■";
				SetColor((int)COLOR::WHITE);
			}
			else if (map[i][j] == (char)OBJ_TYPE::ANIMAL)
			{
				SetColor((int)COLOR::YELLOW);
				std::cout << "↑";
				SetColor((int)COLOR::WHITE);
			}
		}
		std::cout << std::endl;
	}

	GotoXY(0,0);
}

void TreeMove(char map[MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (map[i][j] == (char)OBJ_TYPE::TREE)
			{
				if (i <= 0)
				{
					map[i][j] = (char)OBJ_TYPE::MAP;
				}
				else if(map[i][j] == OBJ_TYPE::TREE) 
				{
					map[i - 1][j] = (char)OBJ_TYPE::TREE;
					map[i][j] = (char)OBJ_TYPE::MAP;
				}
			}
		}
	}
	Sleep(250);
}

void AnimalGeneration(char map[MAP_HEIGHT][MAP_WIDTH])
{
	int random = rand() % (MAP_WIDTH - 1);
	map[MAP_HEIGHT - 1][random] = '2';
}

void AnimalMove(char map[MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (map[i][j] == (char)OBJ_TYPE::ANIMAL)
			{
				if (i <= 0)
				{
					map[i][j] = (char)OBJ_TYPE::MAP;
				}
				else
				{
					int randomx = (rand() % 5) - 2;
					int new_j = j + randomx;

					// 경계를 넘는 경우를 처리
					if (new_j < 0)
						new_j = 0;
					else if (new_j >= MAP_WIDTH)
						new_j = MAP_WIDTH - 1;

					if (map[i - 1][new_j] != (char)OBJ_TYPE::TREE &&
						map[i + 1][new_j] != (char)OBJ_TYPE::TREE &&
						map[i - 1][new_j] != (char)OBJ_TYPE::ANIMAL)
					{
						map[i - 1][new_j] = (char)OBJ_TYPE::ANIMAL;
						map[i][j] = (char)OBJ_TYPE::MAP;
					}
				}
			}
		}
	}
}








