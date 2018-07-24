#pragma once
#include <conio.h>
#include <iostream>
#include "Snake.h"
class GameMode
{
public:
	GameMode();
	~GameMode();
 
	int SetDifficulty();
	bool PlayAgain();
	void CheckInpit(Snake &TheSnake, Field &MainField, Direction &HeadDirection);
	void ResetGame(Snake &TheSnake, Field &MainField, Direction &HeadDirection, bool& GameOver, int& Difficulty);

};

