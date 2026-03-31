#ifndef destroyShip_h
#define destroyShip_h


#include "include.h"
#include "playSound.h"

class Ship;

void DestroyingShips(vector<Ship>& ships, vector<Ship>& ships02, int shipsSize, int playerNumber, GameState& gameState);

void ChooseDestroy(vector<Ship>& ships, vector<Ship>& ships02, int shipsSize, GameState& gameState);

#endif // !destroyShip.h