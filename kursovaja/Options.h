#pragma once

#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

class Options
{
public:
	Options(int widthoffield, int heightoffield, int height, int width, int FOW);
	~Options();
	int mazewidth;
	int mazeheight;
	int sendwidth;
	int sendheight;
	int fow;

	void increasewidth();
	void decreasewidth();
	void increaseheight();
	void decreaseheight();
	void Moveupop();
	void Movedownop();
	void Moverightfow(RenderWindow &window);
	void Moveleftfow(RenderWindow &window);
	void drawopmenu(RenderWindow &window,Text &widthtext,Text &heighttext);
	int retrieveop();
	int retrievefow();

	Text textop[4];
	Text textfow[2];

	Font fontop;

private:
	int SelectedNumberOptions;
};

