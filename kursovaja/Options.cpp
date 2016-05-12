#include "Options.h"
#include <sstream>

Options::Options(int widthoffield, int heightoffield, int height, int width, int FOW)
{
	if (!fontop.loadFromFile("arial.ttf"))
	{
		printf("ERROR!!!");
	}

	textop[0].setColor(Color::Green);
	textop[0].setString("Width value");
	textop[0].setFont(fontop);
	textop[0].setPosition(widthoffield / 3, heightoffield / 5 * 1);

	textop[1].setColor(Color::Red);
	textop[1].setString("Height value");
	textop[1].setFont(fontop);
	textop[1].setPosition(widthoffield / 3, heightoffield / 5 * 2);

	textop[2].setColor(Color::Red);
	textop[2].setString("Fog of war");
	textop[2].setFont(fontop);
	textop[2].setPosition(widthoffield / 3, heightoffield / 5 * 3);

	textop[3].setColor(Color::Red);
	textop[3].setString("Return to menu");
	textop[3].setFont(fontop);
	textop[3].setPosition(widthoffield / 3, heightoffield / 5 * 4);


	textfow[0].setColor(Color::White);
	textfow[0].setString("On");
	textfow[0].setFont(fontop);
	textfow[0].setPosition(widthoffield / 3 + 200, heightoffield / 5 * 3);

	textfow[1].setColor(Color::White);
	textfow[1].setString("Off");
	textfow[1].setFont(fontop);
	textfow[1].setPosition(widthoffield / 3 + 200, heightoffield / 5 * 3);

	mazewidth = width;
	mazeheight = height;
	SelectedNumberOptions = 0;
	fow = FOW;
	sendheight = heightoffield;
	sendwidth = widthoffield;
}


Options::~Options()
{
}

void Options::Moveupop()
{
	if (SelectedNumberOptions - 1 >= 0)
	{
		textop[SelectedNumberOptions - 1].setColor(Color::Green);
		textop[SelectedNumberOptions].setColor(Color::Red);
		SelectedNumberOptions--;
	}
}

void Options::Movedownop()
{
	if (SelectedNumberOptions + 1 < 4)
	{
		textop[SelectedNumberOptions + 1].setColor(Color::Green);
		textop[SelectedNumberOptions].setColor(Color::Red);
		SelectedNumberOptions++;
	}
}

void Options::increasewidth()
{
	if (mazewidth < 70)
	{
		mazewidth++;
	}
}

void Options::decreasewidth()
{
	if (mazewidth > 1)
	{
		mazewidth--;
	}
}

void Options::increaseheight()
{
	if (mazeheight < 45)
	{
		mazeheight++;
	}
}

void Options::decreaseheight()
{
	if (mazeheight > 1)
	{
		mazeheight--;
	}
}

int Options::retrieveop()
{
	return SelectedNumberOptions;
}

int Options::retrievefow()
{
	return fow;
}

void Options::Moverightfow(RenderWindow &window)
{
	if (fow + 1 < 2)
	{
		fow++;
		window.clear(Color::Black);
	}
}

void Options::Moveleftfow(RenderWindow &window)
{
	if (fow - 1 >= 0)
	{
		fow--;
		window.clear(Color::Black);
	}
}

void Options::drawopmenu(RenderWindow &window ,Text &heighttext, Text &widthtext)
{
	window.draw(textop[0]);
	window.draw(textop[1]);
	window.draw(textop[2]);
	window.draw(textop[3]);
	window.draw(textfow[fow]);
	window.draw(widthtext);
	window.draw(heighttext);
}


