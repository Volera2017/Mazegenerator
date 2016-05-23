#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#define MAX_NUMBER_OF_ITEMS 4
class Menu
{
public:
	Menu(int widthfield, int heightfield);
	~Menu();

	void drawwindow(RenderWindow &window);
	void Moveup();
	void Movedown();
	int RetrieveNumber();

private :
	int SelectedNumberItem;

	Font fontmenu;

	Text textmenu[MAX_NUMBER_OF_ITEMS];
};
