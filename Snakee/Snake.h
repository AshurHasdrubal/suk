#pragma once
#include "Field.h"

class Field;
enum Direction
{
	UP,
	Down,
	Right,
	Left
};

class SnakeTale
{
public:
	int PosX;
	int PosY;
	int PrevX;
	int PrevY;

};
 

class Snake
{
public:
	Snake();
	~Snake();


	SnakeTale * TaleAr = new SnakeTale[1];
	int SnakeLength = 1;
	Direction HeadDirection = UP;
	int PositionX = 5;
	int PositionY = 5;
	int Score = 0;

	void AddLenth();
	void MoveSnakeTale();
	void Eat(Field& Field);
	 
};

