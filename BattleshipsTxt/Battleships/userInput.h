#ifndef userInput_h
#define userInput_h

#include "include.h"
class Ship;

bool CheckShipPlaced(vector<Ship> ships, int userInput);

bool CheckValidInt(int min, int max, vector<Ship> ships, int userInput);

bool CheckValidChar(char userInput);

bool CheckQuit(GameState& gameState, string userInput);

void TakeInput(int min, int max, vector<Ship>& ships, GameState& gameState, int& X, char& Y, ConvertType convert);

void CheckValidXY(int& userInputX, char& userInputY, vector<Ship> ships, GameState& gameState);

#endif //userInput.h