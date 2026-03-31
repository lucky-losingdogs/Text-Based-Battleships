#include "userInput.h"
#include "ship.h"

bool CheckShipPlaced(vector<Ship> ships, int userInput)
{
	if (ships[userInput].placed)
	{
		cout << "\n>>Invalid input! Please try again:";
		return true;
	}
	else return false;
}

bool CheckValidInt(int min, int max, vector<Ship> ships, int userInput)
{
	//invalid input if string or lower than min param or higher than max param
	if (userInput < min || userInput > max)
	{
		cout << "\n>>Invalid input! Please try again:";
		return false;
	}
	else
	{
		return true;
	}
}


bool CheckValidChar(char userInput)
{
	//compares the input to if its in the gridLettersCheck string
	if(gridLettersCheck.find(userInput) == string::npos)
	{
		cout << "\n>>Invalid input! Please try again:";
		return false;
	}
	else
	{
		return true;
	}

}


//check if user wants to exit
bool CheckQuit(GameState& gameState, string userInput)
{
	for (int i = 0; i < userInput.size(); i++)
	{
		userInput[i] = tolower(userInput[i]);		//converts everything in the input to lowercase
	}

	if (userInput == "quit" || userInput == "exit" || userInput == "q" || userInput == "end")
	{
		gameState.running = false;
		exit(quit);
	}
	else return false;
}


void TakeInput(int min, int max, vector<Ship>& ships, GameState& gameState, int& X, char& Y, ConvertType convert)
{
	string userInput;

	while (true)
	{
		cout << "\n>";
		getline(cin, userInput);

		if (userInput.empty())
		{
			cin.clear();
			cout << "\n>>Empty input! Please try again:";
			continue;
		}


		if (CheckQuit(gameState, userInput))
			return;


		if (convert == ConvertType::toInt)	//if input is supposed to be a number, convert the string input to int, then pass it by ref to CheckValidInt
		{
			int num;
			stringstream ss(userInput);
			if (!(ss >> num) || !(ss.eof()))				//if the input isn't an int, it returns false
				num = 1000;					//if false, set value to be completely out of range so it's invalid

			if (CheckValidInt(min, max, ships, num))
			{
				X = num;
				break;
			}
			else
			{
				continue;
			}
		}
		else if (convert == ConvertType::toChar)	//if input is supposed to be a char, uppercase the first letter and pass that as the input
		{
			char letter = toupper(userInput[0]);
			
			if (CheckValidChar(letter))
			{
				Y = letter;
				break;	
			}
			else
			{
				continue;
			}
		}
	}
}


void CheckValidXY(int& userInputX, char& userInputY, vector<Ship> ships, GameState& gameState)
{
	cout << "\n>>x: ";
	TakeInput(1, 10, ships, gameState, userInputX, userInputY, toInt);	//prompts for input, checks if input is an int, and between 1-10

	cout << "\n>>y: ";
	TakeInput(0, 0, ships, gameState, userInputX, userInputY, toChar);;			//prompts for input, compares char to a string of valid chars
}