#include "Snake.h"



Snake::Snake()
{
};


Snake::~Snake()
{
};

void Snake::AddLenth()
{
	SnakeLength += 1;
	SnakeTale* Temp = nullptr;
	if (SnakeLength > 2)
	{
		Temp = TaleAr;
		TaleAr = new SnakeTale[SnakeLength - 1];
		for (int i = 0; i < SnakeLength - 1; i++)
		{
			TaleAr[i] = Temp[i];
		}
		if (Temp != nullptr)
		{
			delete[] Temp;
		}
	}
};

void Snake::MoveSnakeTale()
{
	for (int g = 0; g < SnakeLength - 1; g++)
	{
		if (g == 0)
		{
			TaleAr[0].PrevX = TaleAr[0].PosX;
			TaleAr[0].PrevY = TaleAr[0].PosY;
		    TaleAr[0].PosX =  PositionX;
			TaleAr[0].PosY =  PositionY;
		}
		else if (g>0)
		{
			TaleAr[g].PrevX = TaleAr[g].PosX;
			TaleAr[g].PrevY = TaleAr[g].PosY;
			TaleAr[g].PosX = TaleAr[g - 1].PrevX;
			TaleAr[g].PosY = TaleAr[g - 1].PrevY;
		}

	}
};

void Snake::Eat(Field& Field)
{
	if (PositionX == Field.FoodX && PositionY == Field.FoodY)
	{
		Score += 10;
		AddLenth();
		Field.SpawnFood();
	}
}
