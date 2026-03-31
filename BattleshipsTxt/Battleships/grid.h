#ifndef grid_h
#define grid_h

#include "include.h"

class Ship;

void DrawGrid(vector<Ship>& ships, int shipsSize, MarkGridType markGridType);

void MarkChooseShip(vector<Ship>& ships, int shipsSize, vector<vector<char>>& grid);

void MarkDestroyShip(vector<Ship>& ships, int shipsSize, vector<vector<char>>& grid);

#endif // grid_h