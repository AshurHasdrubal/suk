#include "Snake.h"
#include "Field.h"
#include <iostream>
#include <chrono>
#include <conio.h>
#include <thread>
#include <ctime>
#include "GameMode.h"

int main()
{
	Snake TheSnake;
	Field MainField(&TheSnake);
	GameMode GameMode;
	bool GameOver = false;
	Direction HeadDirection = UP;
	int Difficulty;
	std::srand(std::time(NULL));
	do {
		GameMode.ResetGame(TheSnake, MainField, HeadDirection, GameOver, Difficulty);
		system("cls");
		while (!GameOver)
		{
			
			std::this_thread::sleep_for(std::chrono::milliseconds(Difficulty));
			GameMode.CheckInpit(TheSnake, MainField, HeadDirection);
			switch (HeadDirection)
			{
			case UP:
					TheSnake.MoveSnakeTale();
					TheSnake.PositionY -= 1;
					if (TheSnake.PositionY < 1) TheSnake.PositionY = MainField.Hight - 2;
					TheSnake.Eat(MainField);
					break;

			case Down:
				TheSnake.MoveSnakeTale();
					TheSnake.PositionY += 1;
					if (TheSnake.PositionY > MainField.Hight - 2) TheSnake.PositionY = 1;
					TheSnake.Eat(MainField);
					break;

			case Right:
					TheSnake.MoveSnakeTale();
					TheSnake.PositionX += 1;
					if (TheSnake.PositionX > MainField.Width - 2) TheSnake.PositionX = 1;
					TheSnake.Eat(MainField);
					break;

			case Left:
					TheSnake.MoveSnakeTale();
					TheSnake.PositionX -= 1;
					if (TheSnake.PositionX < 1) TheSnake.PositionX = MainField.Width - 2;
					TheSnake.Eat(MainField);
					break;
			
			}

			if (MainField.IsTaleThere(TheSnake.PositionY, TheSnake.PositionX))
			{
				GameOver = true;
			};

			system("cls");
			MainField.PrintField();
			std::cout << std::endl << std::endl << "Score: " << TheSnake.Score;
		}
		system("cls");
		std::cout << std::endl << "Game Over\n";
		std::cout << "try again? 0/1\n";

	} while (GameMode.PlayAgain());

	system("Pause");
	return 0;
}