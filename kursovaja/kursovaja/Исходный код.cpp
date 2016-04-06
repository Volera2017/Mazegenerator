#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stack>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace std;
using namespace sf;

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

int main(int argc, char **argv)
{
	int width, height;
	printf("Please,enter the width and height values(width <= 70 , height <= 45)\n");
	scanf_s("%d\n%d", &width, &height);
	Cell **labyrinth = new Cell*[width];
	for (int i = 0; i < width; i++)
	{
		labyrinth[i] = new Cell[height];
	}

	//заполняем начальные данные для ячеек
	for (int y = 0; y < height; y++)
	for (int x = 0; x < width; x++)
	{
		labyrinth[x][y].x = x;
		labyrinth[x][y].y = y;
		labyrinth[x][y].Visited = false;
		labyrinth[x][y].Left = Close;
		labyrinth[x][y].Right = Close;
		labyrinth[x][y].Top = Close;
		labyrinth[x][y].Bottom = Close;
	}

	//Выбираем первую ячейку откуда начнем движение
	srand(time(NULL));
	int startX = rand() % width;
	int startY = rand() % height;

	labyrinth[startX][startY].Visited = true;

	//Заносим нашу ячейке в path и начинаем строить путь
	stack <Cell> path;
	path.push(labyrinth[startX][startY]);

	while (!path.empty())
	{
		Cell _cell = path.top();

		//смотрим варианты, в какую сторону можно пойти
		vector <Cell> nextStep;
		if (_cell.x > 0 && (labyrinth[_cell.x - 1][_cell.y].Visited == false))
			nextStep.push_back(labyrinth[_cell.x - 1][_cell.y]);
		if (_cell.x < width - 1 && (labyrinth[_cell.x + 1][_cell.y].Visited == false))
			nextStep.push_back(labyrinth[_cell.x + 1][_cell.y]);
		if (_cell.y > 0 && (labyrinth[_cell.x][_cell.y - 1].Visited == false))
			nextStep.push_back(labyrinth[_cell.x][_cell.y - 1]);
		if (_cell.y < height - 1 && (labyrinth[_cell.x][_cell.y + 1].Visited == false))
			nextStep.push_back(labyrinth[_cell.x][_cell.y + 1]);

		if (!nextStep.empty())
		{
			//выбираем сторону из возможных вариантов
			Cell next = nextStep[rand() % nextStep.size()];

			//Открываем сторону, в которую пошли на ячейках
			if (next.x != _cell.x)
			{
				if (_cell.x - next.x > 0)
				{
					labyrinth[_cell.x][_cell.y].Left = Open;
					labyrinth[next.x][next.y].Right = Open;
				}
				else
				{
					labyrinth[_cell.x][_cell.y].Right = Open;
					labyrinth[next.x][next.y].Left = Open;
				}
			}
			if (next.y != _cell.y)
			{
				if (_cell.y - next.y > 0)
				{
					labyrinth[_cell.x][_cell.y].Top = Open;
					labyrinth[next.x][next.y].Bottom = Open;
				}
				else
				{
					labyrinth[_cell.x][_cell.y].Bottom = Open;
					labyrinth[next.x][next.y].Top = Open;
				}
			}

			labyrinth[next.x][next.y].Visited = true;
			path.push(next);

		}
		else
		{
			//если пойти никуда нельзя, возвращаемся к предыдущему узлу
			path.pop();
		}
	}

	int heightfield = height * 30;
	int widthfield = width * 30;
	int step = 30;
	int ypos = 10;
	int xpos = 10;
	int dest = 0;
	int stepamount = 0;
	bool boo;
	const Time duration = seconds(3.0f);
	const string str = "Congratulations!!!";

	SoundBuffer soundbuffer;

	SoundBuffer soundback;

	Sound sound;
	soundbuffer.loadFromFile("button.wav");
	sound.setBuffer(soundbuffer);
	sound.setPitch(0.75f);
	sound.setVolume(20);

	Sound soundbackground;
	soundback.loadFromFile("back.wav");
	soundbackground.setBuffer(soundback);
	soundbackground.setPitch(0.75f);
	soundbackground.setVolume(20);
	soundbackground.setLoop(true);
	
	Font font;
	font.loadFromFile("arial.ttf");
	
	Text text(str,font);
	text.setPosition(widthfield / 2, heightfield / 2);

	Text score("",font);
	score.setPosition(10, heightfield);
	
	RenderWindow window(VideoMode(widthfield, heightfield + 60), "Maze Field",Style::Fullscreen);

	Texture image;
	image.loadFromFile("imagedizel.jpg");

	Sprite sprite;
	sprite.setTexture(image);
	sprite.setScale(8.5f,7.4f);

	RectangleShape finish(Vector2f(30, 30));
	finish.setFillColor(Color::Green);
	finish.setPosition(widthfield - 30, heightfield - 30);

	RectangleShape circle(Vector2f(15,15));
	circle.setFillColor(Color::Red);
	circle.setPosition(xpos, ypos);

	RectangleShape enemy1(Vector2f(15, 15));
	enemy1.setPosition(widthfield - 30, heightfield - 30);
	enemy1.setFillColor(Color::Blue);
	int enemy1x = width;
	int enemy1y = height;

	//Starting painting boundaries
	VertexArray linetop(Lines, 2);
	linetop[0] = Vector2f(10, 10);
	linetop[1] = Vector2f(widthfield, 10);

	VertexArray linebottom(Lines, 2);
	linebottom[0] = Vector2f(10, heightfield);
	linebottom[1] = Vector2f(widthfield, heightfield);

	VertexArray lineleft(Lines, 2);
	lineleft[0] = Vector2f(10, 10);
	lineleft[1] = Vector2f(10, heightfield);

	VertexArray lineright(Lines, 2);
	lineright[0] = Vector2f(widthfield, 10);
	lineright[1] = Vector2f(widthfield, heightfield);
	// end painting boundaries
	soundbackground.play();

	while (window.isOpen())
	{
		Event event;
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
						playerscore.clear();
						xpos -= step;
						stepamount++;
						playerscore << stepamount;
						score.setString("Number of steps : " + playerscore.str());
						sound.play();
						circle.setFillColor(Color::Black);
						circle.setPosition(xpos, ypos);
						circle.setFillColor(Color::Red);
						window.draw(circle);
						window.display();
					}
				}
				if (event.key.code == Keyboard::Right)
				{
					if ((xpos < widthfield - step - 5) && (labyrinth[xpos / 30][ypos / 30].Right == Open))
					{
						playerscore.clear();
						xpos += step;
						stepamount++;
						playerscore << stepamount;
						score.setString("Number of steps : " + playerscore.str());
						sound.play();
						circle.setFillColor(Color::Black);
						circle.setPosition(xpos, ypos);
						circle.setFillColor(Color::Red);
						window.draw(circle);
						window.display();
					}
				}
				if (event.key.code == Keyboard::Up)
				{
					if ((ypos > step + 5) && (labyrinth[xpos / 30][ypos / 30].Top == Open))
					{
						playerscore.clear();
						ypos -= step;
						stepamount++;
						playerscore << stepamount;
						score.setString("Number of steps : " + playerscore.str());
						sound.play();
						circle.setFillColor(Color::Black);
						circle.setPosition(xpos, ypos);
						circle.setFillColor(Color::Red);
						window.draw(circle);
						window.display();
					}
				}
				if (event.key.code == Keyboard::Down)
				{
					if ((ypos < heightfield - step - 5) && (labyrinth[xpos / 30][ypos / 30].Bottom == Open))
					{
						playerscore.clear();
						ypos += step;
						stepamount++;
						playerscore << stepamount;
						score.setString("Number of steps : " + playerscore.str());
						sound.play();
						circle.setFillColor(Color::Black);
						circle.setPosition(xpos, ypos);
						circle.setFillColor(Color::Red);
						window.draw(circle);
						window.display();
					}
				}
			}

			if ((xpos + 5 >= widthfield - 30) && (ypos + 5 >= heightfield - 30))
			{

				window.clear(Color::Black);
				window.draw(sprite);
				window.display();
				sleep(duration);
				return 0;
			}
		}

		if ((xpos > 0) && (heightfield - ypos > 0))
		{
			window.clear(Color::Black);
			window.draw(circle);
			window.draw(finish);
			window.draw(linetop);
			window.draw(lineleft);
			window.draw(linebottom);
			window.draw(lineright);
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < height; j++)
				{
					if (labyrinth[i][j].Left == 0)
					{
						lineleft[0] = Vector2f(30 * i, 30 * j);
						lineleft[1] = Vector2f(30 * i, 30 * j + 30);
					}
					window.draw(lineleft);
					if (labyrinth[i][j].Top == Close)
					{
						linetop[0] = Vector2f(30 * i, 30 * j);
						linetop[1] = Vector2f(30 * i + 30, 30 * j);
					}
					window.draw(linetop);
				}
			}
		}

		window.draw(score);
		window.display();
	}
		return 0;
	}