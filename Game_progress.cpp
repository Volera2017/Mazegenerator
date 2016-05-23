#include "Descriptionofvar.h"

void game_progress(Cell** labyrinth)
{
	int heightfield = height * 30;
	int widthfield = width * 30;
	int step = 30;
	int ypos = 10;
	int xpos = 10;
	int dest = 0;
	int stepamount = 0;
	bool boo = false;
	const Time duration = seconds(4.0f);
	const string str = "Congratulations!!!";
	int newcount = 0;

	SoundBuffer soundbuffer;

	SoundBuffer soundback;

	Sound sound;
	soundbuffer.loadFromFile("button.wav");
	sound.setBuffer(soundbuffer);
	sound.setPitch(0.75f);
	sound.setVolume(20);

	Sound soundbackground;
	soundback.loadFromFile("phar.wav");
	soundbackground.setBuffer(soundback);
	soundbackground.setPitch(1.f);
	soundbackground.setVolume(20);
	soundbackground.setLoop(true);

	Font font;
	font.loadFromFile("arial.ttf");

	Text text(str, font);
	text.setPosition((float)widthfield / 2 - 100, (float)heightfield / 2);

	Text score("", font);
	score.setPosition(10, (float)heightfield);

	RenderWindow window(VideoMode(widthfield, heightfield + 60), "Maze Field");

	Texture MYcharacter;
	MYcharacter.loadFromFile("imch.png");

	Texture dark1;
	dark1.loadFromFile("dark.png");

	Texture dark2;
	dark2.loadFromFile("dark.png");

	Texture dark3;
	dark3.loadFromFile("dark.png");

	Texture dark4;
	dark4.loadFromFile("dark.png");

	Image screen;

	RectangleShape finish(Vector2f(30, 30));
	finish.setFillColor(Color::Green);
	finish.setPosition((float)widthfield - 30, (float)heightfield - 30);

	RectangleShape circle(Vector2f(15, 15));
	circle.setFillColor(Color::Black);
	circle.setPosition((float)xpos, (float)ypos);

	Sprite character;
	character.setTexture(MYcharacter);
	character.setScale(0.08f, 0.08f);
	character.setPosition((float)xpos, (float)ypos);

	//Starting painting boundaries
	VertexArray linetop(Lines, 2);
	linetop[0] = Vector2f(10, 10);
	linetop[1] = Vector2f((float)widthfield, 10);

	VertexArray linebottom(Lines, 2);
	linebottom[0] = Vector2f(10, (float)heightfield);
	linebottom[1] = Vector2f((float)widthfield, (float)heightfield);

	VertexArray lineleft(Lines, 2);
	lineleft[0] = Vector2f(10, 10);
	lineleft[1] = Vector2f(10, (float)heightfield);

	VertexArray lineright(Lines, 2);
	lineright[0] = Vector2f((float)widthfield, 10);
	lineright[1] = Vector2f((float)widthfield, (float)heightfield);
	// end painting boundaries
	soundbackground.play();

	Sprite night1;
	night1.setTexture(dark1);
	night1.setScale(20.0f, 15.5f);//*20.0f, 15.5f
	night1.setPosition((float)xpos - 3000, (float)ypos - 3000 - number * 30);

	Sprite night2;
	night2.setTexture(dark2);
	night2.setScale(20.0f, 20.0f);//*20.0f, 20.0f
	night2.setPosition((float)xpos + number * 30, (float)ypos - 3000);

	Sprite night3;
	night3.setTexture(dark3);
	night3.setScale(11.62f, 20.0f);//*11.62f, 20.0f
	night3.setPosition((float)xpos - 3000 - number * 30, (float)ypos - 3000);

	Sprite night4;
	night4.setTexture(dark4);
	night4.setScale(20.0f, 10.0f);//*20.0f, 10.0f
	night4.setPosition((float)xpos - 3000, (float)ypos + number * 30);

	while (window.isOpen())
	{
		Event event;
		window.clear(Color::Black);
		window.draw(finish);
		window.draw(linebottom);
		window.draw(lineright);
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if (labyrinth[i][j].Left == 0)
				{
					lineleft[0] = Vector2f((float)30 * i, (float)30 * j);
					lineleft[1] = Vector2f((float)30 * i, (float)30 * j + 30);
				}
				window.draw(lineleft);
				if (labyrinth[i][j].Top == Close)
				{
					linetop[0] = Vector2f((float)30 * i, (float)30 * j);
					linetop[1] = Vector2f((float)30 * i + 30, (float)30 * j);
				}
				window.draw(linetop);
			}
		}
		if (!boo)
		{
			window.display();
			sleep(duration);

		}
		if (fog == 0)
		{
			window.draw(night1);
			window.draw(night2);
			window.draw(night3);
			window.draw(night4);
		}
		window.draw(character);
		if (!boo)
		{
			boo = true;
			screen = window.capture();
			screen.saveToFile("screen.png");
		}
		window.draw(score);
		window.display();
		while (window.pollEvent(event))
		{
			ostringstream playerscore;
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
				{
					if ((xpos > step + 5) && (labyrinth[xpos / 30][ypos / 30].Left == Open))
					{
						circle.setPosition((float)xpos, (float)ypos);
						playerscore.clear();
						xpos -= step;
						stepamount++;
						playerscore << stepamount;
						score.setString("Steps : " + playerscore.str());
						sound.play();
						character.setPosition((float)xpos, (float)ypos);
						night1.setPosition((float)xpos - 3000, (float)ypos - 3000 - number * 30);
						night2.setPosition((float)xpos + number * 30, (float)ypos - 3000);
						night3.setPosition((float)xpos - 3000 - number * 30, (float)ypos - 3000);
						night4.setPosition((float)xpos - 3000, (float)ypos + number * 30);
						window.draw(linebottom);
						window.draw(lineright);
						for (int i = 0; i < width; i++)
						{
							for (int j = 0; j < height; j++)
							{
								if (labyrinth[i][j].Left == 0)
								{
									lineleft[0] = Vector2f((float)30 * i, (float)30 * j);
									lineleft[1] = Vector2f((float)30 * i, (float)30 * j + 30);
								}
								window.draw(lineleft);
								if (labyrinth[i][j].Top == Close)
								{
									linetop[0] = Vector2f((float)30 * i, (float)30 * j);
									linetop[1] = Vector2f((float)30 * i + 30, (float)30 * j);
								}
								window.draw(linetop);
							}
						}
						window.draw(character);
						if (fog == 0)
						{
							window.draw(night1);
							window.draw(night2);
							window.draw(night3);
							window.draw(night4);
						}
						window.display();
					}
				}
				if (event.key.code == Keyboard::Right)
				{
					if ((xpos < widthfield - step - 5) && (labyrinth[xpos / 30][ypos / 30].Right == Open))
					{
						circle.setPosition((float)xpos, (float)ypos);
						playerscore.clear();
						xpos += step;
						stepamount++;
						playerscore << stepamount;
						score.setString("Steps : " + playerscore.str());
						sound.play();
						character.setPosition((float)xpos, (float)ypos);
						night1.setPosition((float)xpos - 3000, (float)ypos - 3000 - number * 30);
						night2.setPosition((float)xpos + number * 30, (float)ypos - 3000);
						night3.setPosition((float)xpos - 3000 - number * 30, (float)ypos - 3000);
						night4.setPosition((float)xpos - 3000, (float)ypos + number * 30);
						window.draw(linebottom);
						window.draw(lineright);
						for (int i = 0; i < width; i++)
						{
							for (int j = 0; j < height; j++)
							{
								if (labyrinth[i][j].Left == 0)
								{
									lineleft[0] = Vector2f((float)30 * i, (float)30 * j);
									lineleft[1] = Vector2f((float)30 * i, (float)30 * j + 30);
								}
								window.draw(lineleft);
								if (labyrinth[i][j].Top == Close)
								{
									linetop[0] = Vector2f((float)30 * i, (float)30 * j);
									linetop[1] = Vector2f((float)30 * i + 30, (float)30 * j);
								}
								window.draw(linetop);
							}
						}
						window.draw(character);
						if (fog == 0)
						{
							window.draw(night1);
							window.draw(night2);
							window.draw(night3);
							window.draw(night4);
						}
						window.display();
					}
				}
				if (event.key.code == Keyboard::Up)
				{
					if ((ypos > step + 5) && (labyrinth[xpos / 30][ypos / 30].Top == Open))
					{
						circle.setPosition((float)xpos, (float)ypos);
						playerscore.clear();
						ypos -= step;
						stepamount++;
						playerscore << stepamount;
						score.setString("Steps : " + playerscore.str());
						sound.play();
						character.setPosition((float)xpos, (float)ypos);
						night1.setPosition((float)xpos - 3000, (float)ypos - 3000 - number * 30);
						night2.setPosition((float)xpos + number * 30, (float)ypos - 3000);
						night3.setPosition((float)xpos - 3000 - number * 30, (float)ypos - 3000);
						night4.setPosition((float)xpos - 3000, (float)ypos + number * 30);
						window.draw(linebottom);
						window.draw(lineright);
						for (int i = 0; i < width; i++)
						{
							for (int j = 0; j < height; j++)
							{
								if (labyrinth[i][j].Left == 0)
								{
									lineleft[0] = Vector2f((float)30 * i, (float)30 * j);
									lineleft[1] = Vector2f((float)30 * i, (float)30 * j + 30);
								}
								window.draw(lineleft);
								if (labyrinth[i][j].Top == Close)
								{
									linetop[0] = Vector2f((float)30 * i, (float)30 * j);
									linetop[1] = Vector2f((float)30 * i + 30, (float)30 * j);
								}
								window.draw(linetop);
							}
						}
						window.draw(character);
						if (fog == 0)
						{
							window.draw(night1);
							window.draw(night2);
							window.draw(night3);
							window.draw(night4);
						}
						window.display();
					}
				}
				if (event.key.code == Keyboard::Down)
				{
					if ((ypos < heightfield - step - 5) && (labyrinth[xpos / 30][ypos / 30].Bottom == Open))
					{
						circle.setPosition((float)xpos, (float)ypos);
						playerscore.clear();
						ypos += step;
						stepamount++;
						playerscore << stepamount;
						score.setString("Steps : " + playerscore.str());
						sound.play();
						character.setPosition((float)xpos, (float)ypos);
						night1.setPosition((float)xpos - 3000, (float)ypos - 3000 - number * 30);
						night2.setPosition((float)xpos + number * 30, (float)ypos - 3000);
						night3.setPosition((float)xpos - 3000 - number * 30, (float)ypos - 3000);
						night4.setPosition((float)xpos - 3000, (float)ypos + number * 30);
						window.draw(linebottom);
						window.draw(lineright);
						for (int i = 0; i < width; i++)
						{
							for (int j = 0; j < height; j++)
							{
								if (labyrinth[i][j].Left == 0)
								{
									lineleft[0] = Vector2f((float)30 * i, (float)30 * j);
									lineleft[1] = Vector2f((float)30 * i, (float)30 * j + 30);
								}
								window.draw(lineleft);
								if (labyrinth[i][j].Top == Close)
								{
									linetop[0] = Vector2f((float)30 * i, (float)30 * j);
									linetop[1] = Vector2f((float)30 * i + 30, (float)30 * j);
								}
								window.draw(linetop);
							}
						}
						if (fog == 0)
						{
							window.draw(night1);
							window.draw(night2);
							window.draw(night3);
							window.draw(night4);
						}
						window.draw(character);
						window.display();
					}
				}
				if ((xpos + 5 > widthfield - 30) && (ypos + 5 > heightfield - 30))
				{
					character.setColor(Color::Black);
					window.clear(Color::Black);
					window.draw(text);
					window.display();
					sleep(duration);
					RenderWindow restart(VideoMode(600, 600), "Restart", Style::Default);
					Restart R;
					window.close();
					while (restart.isOpen())
					{
						restart.draw(spritemenu);
						R.drawing(restart);
						restart.display();
						Event event1;
						while (restart.pollEvent(event1))
						{
							if (event1.type == Event::KeyPressed)
							{
								if (event1.key.code == Keyboard::Left)
								{
									restart.clear(Color::Black);
									R.Moveleft();
									newcount = R.Retrievecount();
									R.drawing(restart);
								}

								if (event1.key.code == Keyboard::Right)
								{
									restart.clear(Color::Black);
									R.Moveright();
									newcount = R.Retrievecount();
									R.drawing(restart);
									restart.display();
								}

								if (event1.key.code == Keyboard::Return)
								{
									switch (newcount)
									{
									case 0:
									{
											  switcher = 0;
											  restart.close();
											  break;
									}
									case 1:
									{
											  switcher = 1;
											  restart.close();
											  break;
									}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

