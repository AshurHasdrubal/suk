#pragma once
#include <iostream>
#include "Snake.h"

class Snake;

class Field
{
public:
	Field(Snake * Snake);
	~Field();

	Snake * SnakeRef;

	int Hight = 20;
	int Width = 20;
	int FoodX;
	int FoodY;

	bool IsTaleThere(int hi, int wi);
	void PrintField();
	void SpawnFood();

};

