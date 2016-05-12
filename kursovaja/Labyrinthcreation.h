#include<iostream>
#include "Cell.h"


void input()
{
	int width, height;
	printf("Please,enter the width and height values(width <= 70 , height <= 45)\n");
	scanf_s("%d\n%d", &width, &height);
	Cell **labyrinth = new Cell*[width];
	for (int i = 0; i < width; i++)
	{
		labyrinth[i] = new Cell[height];
	}
}