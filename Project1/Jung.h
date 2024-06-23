#pragma once
const int MAP_WIDTH = 52;
const int MAP_HEIGHT = 36;


void TreeGeneration(char map[MAP_HEIGHT][MAP_WIDTH]);
void Render(char map[MAP_HEIGHT][MAP_WIDTH]);
void TreeMove(char map[MAP_HEIGHT][MAP_WIDTH]);
void AnimalGeneration(char map[MAP_HEIGHT][MAP_WIDTH]);
void AnimalMove(char map[MAP_HEIGHT][MAP_WIDTH]);