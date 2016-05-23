#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Difficulty
{
public:
	Difficulty(int widthoffield, int heightoffield, int Sel);
	~Difficulty();

	void drawwindow(RenderWindow &window);
	void Moveright(RenderWindow &window);
	void Moveleft(RenderWindow &window);
	void Movedowndif();
	void Moveupdif();
	int RetrieveNumber();
	int RetrieveSelected();

private:
	
	int SelectedNumberDif;
    int Selected;

	Font fontmenu;

	Text diftext[2];
	Text dif[5];
};
