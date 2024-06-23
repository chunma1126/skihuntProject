#include<iostream>
#include <Windows.h>
#include <time.h>
#include "consoleHeader.h"
#include "Jung.h"
#include "TestMain.h"
#include "titleScene.h"

int main()
{
    system("title ��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű�����ͽ�Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű��Ű������ | mode con cols=104 lines=52");
    CursorVis(false, 1);
    LockResize();

    char _map[MAP_HEIGHT][MAP_WIDTH]{};
    srand((unsigned)time(NULL));

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            (_map[i][j] = '0');
        }
    }
    LockResize();

	if (!Title())
		return 0;
	else
	{

		// ���� ����.
		while (true)
		{
            clock_t start_timeTree = clock();
            clock_t start_timeAnimal = clock();
            const float treeInterval = 1.5f;
            const float animalInterval = 3.2f;

            while (true) {
                Render(_map);

                clock_t current_time = clock();
                float elapsed_timeTree = float(current_time - start_timeTree) / CLOCKS_PER_SEC;
                float elapsed_timeAnimal = float(current_time - start_timeAnimal) / CLOCKS_PER_SEC;

                if (elapsed_timeTree >= treeInterval) {
                    TreeGeneration(_map);
                    start_timeTree = clock();
                }

                if (elapsed_timeAnimal >= animalInterval) {
                    AnimalGeneration(_map);
                    start_timeAnimal = clock();
                }

                AnimalMove(_map);
                TreeMove(_map);

            }
		}
	}

	

    

    return 0;
}

