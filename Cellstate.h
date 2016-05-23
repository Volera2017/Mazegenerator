#pragma once

#include <cstdlib>

enum CellState { Close, Open };
class Cell
{
public:
	int x;
	int y;
	CellState Left;
	CellState Right;
	CellState Top;
	CellState Bottom;
	bool Visited;
};