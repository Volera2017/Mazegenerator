#include "Restart.h"

Restart::Restart()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		printf("ERROR!!!");
	}
	textrest[0].setColor(Color::Green);
	textrest[0].setString("Restart");
	textrest[0].setFont(font);
	textrest[0].setPosition(175, 250);

	textrest[1].setColor(Color::Red);
	textrest[1].setString("Exit");
	textrest[1].setFont(font);
	textrest[1].setPosition(375, 250);

	advice[0].setColor(Color::White);
	advice[0].setString("Want to play again?");
	advice[0].setFont(font);
	advice[0].setPosition(180, 100);

	int count = 0;
}

Restart::~Restart()
{
}

void Restart::Moveleft()
{
	if (count - 1 >= 0)
	{
		textrest[count].setColor(Color::Red);
		count--;
		textrest[count].setColor(Color::Green);
	}
}

void Restart::Moveright()
{
	if (count + 1 < 2)
	{
		textrest[count].setColor(Color::Red);
		count++;
		textrest[count].setColor(Color::Green);
	}
}

int Restart::Retrievecount()
{
	return count;
}

void Restart::drawing(RenderWindow &window)
{
	window.draw(textrest[0]);
	window.draw(textrest[1]);
	window.draw(advice[0]);
}