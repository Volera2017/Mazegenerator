#include "Difficulty.h"

Difficulty::Difficulty(int widthoffield, int heightoffield, int Sel)
{
	if (!fontmenu.loadFromFile("arial.ttf"))
	{
		printf("ERROR!!!");
	}

	diftext[0].setFont(fontmenu);
	diftext[0].setColor(Color::Red);
	diftext[0].setString("Difficulty : ");
	diftext[0].setPosition(widthoffield / 4, heightoffield / 2 - 50);

	diftext[1].setFont(fontmenu);
	diftext[1].setColor(Color::White);
	diftext[1].setString("Back to menu");
	diftext[1].setPosition(widthoffield / 4, heightoffield / 2 + 100);


	dif[0].setFont(fontmenu);
	dif[0].setColor(Color::White);
	dif[0].setString("WTF????!!!!");
	dif[0].setPosition(widthoffield / 4 + 200, heightoffield / 2 - 50);

	dif[1].setFont(fontmenu);
	dif[1].setColor(Color::White);
	dif[1].setString("HELL!");
	dif[1].setPosition(widthoffield / 4 + 200, heightoffield / 2 - 50);

	dif[2].setFont(fontmenu);
	dif[2].setColor(Color::White);
	dif[2].setString("Hard");
	dif[2].setPosition(widthoffield / 4 + 200, heightoffield / 2 - 50);

	dif[3].setFont(fontmenu);
	dif[3].setColor(Color::White);
	dif[3].setString("Medium");
	dif[3].setPosition(widthoffield / 4 + 200, heightoffield / 2 - 50);

	dif[4].setFont(fontmenu);
	dif[4].setColor(Color::White);
	dif[4].setString("Easy");
	dif[4].setPosition(widthoffield / 4 + 200, heightoffield / 2 - 50);

	SelectedNumberDif = Sel;
	Selected = 0;
}


Difficulty::~Difficulty()
{
}

void Difficulty::drawwindow(RenderWindow &window)
{
		window.draw(diftext[0]);
		window.draw(diftext[1]);
		window.draw(dif[SelectedNumberDif]);
}

void Difficulty::Moveright(RenderWindow &window)
{
	if (SelectedNumberDif - 1 >= 0)
	{
		SelectedNumberDif--;
		window.clear(Color::Black);
	    drawwindow(window);
	}
}

void Difficulty::Moveleft(RenderWindow &window)
{
	if (SelectedNumberDif + 1 < 5)
	{	
		SelectedNumberDif++;
		window.clear(Color::Black);
		drawwindow(window);
	}
}

int Difficulty::RetrieveNumber()
{
	return SelectedNumberDif;
}

int Difficulty::RetrieveSelected()
{
	return Selected;
}

void Difficulty::Moveupdif()
{
	if (Selected - 1 >= 0)
	{
		diftext[Selected - 1].setColor(Color::Red);
		diftext[Selected].setColor(Color::White);
		Selected--;
	}
}

void Difficulty::Movedowndif()
{
	if (Selected + 1 < 2)
	{
		diftext[Selected + 1].setColor(Color::Red);
		diftext[Selected].setColor(Color::White);
		Selected++;
	}
}

