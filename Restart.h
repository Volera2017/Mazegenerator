#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Restart
{
public:

	Restart();
	~Restart();

	int count = 0;
	
	Text textrest[2];
	Text advice[1];
	
	Font font;

	void Moveright();
	void Moveleft();
	void drawing(RenderWindow &window);
	int Retrievecount();

};