#include "Menu.h"


Menu::Menu(int widthoffield, int heightoffield)
{
	if (!fontmenu.loadFromFile("arial.ttf"))
	{
		printf("ERROR!!!");
	}

	textmenu[0].setFont(fontmenu);
	textmenu[0].setColor(Color::Green);
	textmenu[0].setString("Start Maze Genereation");
	textmenu[0].setPosition(widthoffield / 3, heightoffield / (MAX_NUMBER_OF_ITEMS + 1) * 1);

	
	textmenu[1].setFont(fontmenu);
	textmenu[1].setColor(Color::Red);
	textmenu[1].setString("Difficulty");
	textmenu[1].setPosition(widthoffield / 3, heightoffield / (MAX_NUMBER_OF_ITEMS + 1) * 2);


	textmenu[2].setFont(fontmenu);
	textmenu[2].setColor(Color::Red);
	textmenu[2].setString("Options");
	textmenu[2].setPosition(widthoffield / 3, heightoffield / (MAX_NUMBER_OF_ITEMS + 1) * 3);


	textmenu[3].setFont(fontmenu);
	textmenu[3].setColor(Color::Red);
	textmenu[3].setString("Exit");
	textmenu[3].setPosition(widthoffield / 3, heightoffield / (MAX_NUMBER_OF_ITEMS + 1) * 4);

	SelectedNumberItem = 0;

}


Menu::~Menu()
{
}

void Menu::drawwindow(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)\
	{
		window.draw(textmenu[i]);
	}
}

void Menu::Moveup()
{
	if (SelectedNumberItem - 1 >= 0)
	{
		textmenu[SelectedNumberItem - 1].setColor(Color::Green);
		textmenu[SelectedNumberItem].setColor(Color::Red);
		SelectedNumberItem--;
	}
}

void Menu::Movedown()
{
	if (SelectedNumberItem + 1 < MAX_NUMBER_OF_ITEMS)
	{
		textmenu[SelectedNumberItem + 1].setColor(Color::Green);
		textmenu[SelectedNumberItem].setColor(Color::Red);
		SelectedNumberItem++;
	}
}

int Menu::RetrieveNumber()
{
	return SelectedNumberItem;
}

