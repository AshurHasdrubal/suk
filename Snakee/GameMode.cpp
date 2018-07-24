#include "GameMode.h"
 

GameMode::GameMode()
{
}


GameMode::~GameMode()
{
}

int GameMode::SetDifficulty()
{
	int dif;
	std::cout << "Choose difficulty (1-5)\n";
	std::cin >> dif;
	if (dif <= 5 && dif >= 1)
	{
		system("cls");
		return 300 - (dif * 50);
	}
	else
	{
		std::cout << "Idiot! 1-5!";
		
		return SetDifficulty();
	}

}

bool GameMode::PlayAgain()
{
	
	int Try;
	std::cin >> Try;
	if (Try < 0 || Try >1)
	{
		"Suck my dick (0-1)\n";
		return PlayAgain();
	}
	else if (Try == 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void GameMode::CheckInpit(Snake & TheSnake, Field & MainField, Direction & HeadDirection)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if (TheSnake.PositionY - 1 == TheSnake.TaleAr[0].PosY) break;
			else if (TheSnake.PositionY == 1 && TheSnake.TaleAr[0].PosY == MainField.Hight - 2) break;
			else HeadDirection = UP;
			break;
		case 's':
			if (TheSnake.PositionY + 1== TheSnake.TaleAr[0].PosY) break;
			else if (TheSnake.PositionY == MainField.Hight - 2 && TheSnake.TaleAr[0].PosY == 1) break;
			else HeadDirection = Down;
			break;
		case 'd':
			if (TheSnake.PositionX + 1== TheSnake.TaleAr[0].PosX) break;
			else if (TheSnake.PositionX == MainField.Width - 2 && TheSnake.TaleAr[0].PosX == 1) break;
			else HeadDirection = Right;
			break;
		case 'a':
			if (TheSnake.PositionX - 1 == TheSnake.TaleAr[0].PosX) break;
			else if (TheSnake.PositionX == 1 && TheSnake.TaleAr[0].PosX == MainField.Width - 2) break;
			else HeadDirection = Left;
			break;

		}
	}
}

void GameMode::ResetGame(Snake &TheSnake, Field &MainField, Direction &HeadDirection, bool& GameOver, int& Difficulty)
{
	GameOver = false;
	HeadDirection = UP;
	TheSnake.SnakeLength = 1;
	
    Difficulty = SetDifficulty();
	TheSnake.PositionX = 5;
	TheSnake.PositionY = 5;
	MainField.PrintField();
	TheSnake.AddLenth();
	TheSnake.TaleAr[0].PosX = 5;
	TheSnake.TaleAr[0].PosY = 6;
	TheSnake.AddLenth();
	TheSnake.TaleAr[0].PosX = 5;
	TheSnake.TaleAr[0].PosY = 7;
	MainField.SpawnFood();

}