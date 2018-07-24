#include "Field.h"




Field::Field(Snake * snake)
{
	this->SnakeRef = snake;
};

Field::~Field()
{
};

bool Field::IsTaleThere(int hi, int wi)
{
	if (SnakeRef->SnakeLength > 1)
	{
		for (int i = 0; i < SnakeRef->SnakeLength - 1; i++)
		{
			if (SnakeRef->TaleAr[i].PosX == wi && (SnakeRef->TaleAr[i].PosY == hi))
			{
				return true;
			}
		}
	}
			return false;
};

void Field::PrintField()
{
	for (int h = 0; h < Hight; h++)
	{
		for (int w = 0; w < Width; w++)
		{
			if (h == 0 || h == Hight - 1 || w == 0)
			{
				std::cout << '#';
			}
			else if (FoodX == w && FoodY == h)
			{
				std::cout << '@';

			}
			else if ((SnakeRef->PositionX == w && SnakeRef->PositionY == h) || IsTaleThere(h, w))
			{
				std::cout << 'o';
			}
			else if (w != Width - 1)
			{
				std::cout << ' ';
			}
			else
			{
				std::cout << '#';
			}

		}
		std::cout << '\n';
	}

};

void Field::SpawnFood()
{

	FoodX = rand() % Width;
	FoodY = rand() % Hight;

	for (int h = 0; h < Hight; h++)
	{
		for (int w = 0; w < Width; w++)
		{
			if (FoodY == 0 || FoodY == Hight - 1 || FoodX == 0 || FoodX == Width - 1 ||
				(SnakeRef->PositionX == FoodX && SnakeRef->PositionY == FoodY) || IsTaleThere(FoodY, FoodX))
			{
				return SpawnFood();
			}
		}
	}

};
