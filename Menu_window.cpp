#include "Descriptionofvar.h"

void menu_window()
{
	RenderWindow windowmenu(VideoMode(600, 600), "Menu", Style::Titlebar);
	Options opns(windowmenu.getSize().x, windowmenu.getSize().y, height, width, fog);
	Text myheight("10", opns.fontop);
	Text mywidth("10", opns.fontop);
	stringstream nachh;
	stringstream nachw;
	Options options(windowmenu.getSize().x, windowmenu.getSize().y, height, width, fog);

	nachh << options.mazeheight;
	myheight.setString(nachh.str());
	nachw << options.mazeheight;
	mywidth.setString(nachw.str());

	Menu menu(windowmenu.getSize().x, windowmenu.getSize().y);
	Sprite spriteoptions;
	Texture imagebackoptions;

	imagebackoptions.loadFromFile("derevo1.jpg");

	spriteoptions.setTexture(imagebackoptions);
	spriteoptions.setScale(2.4f, 3.4f);

	imagebackmenu.loadFromFile("derevo1.jpg");

	spritemenu.setTexture(imagebackmenu);
	spritemenu.setScale(2.4f, 3.4f);

	windowmenu.clear(Color::Black);

	menu.drawwindow(windowmenu);
	windowmenu.display();

	myheight.setPosition(450, (float)opns.sendheight / 5 * 2);

	mywidth.setPosition(450, (float)opns.sendheight / 5 * 1);
	while (windowmenu.isOpen())
	{
		windowmenu.draw(spritemenu);
		menu.drawwindow(windowmenu);
		windowmenu.display();
		Event event;
		while (windowmenu.pollEvent(event))
		{
			booll = true;
			windowmenu.clear(Color::Black);
			windowmenu.draw(spritemenu);
			if (event.type == Event::Closed)
			{
				windowmenu.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)
				{
					menu.Moveup();
					num = menu.RetrieveNumber();
					menu.drawwindow(windowmenu);
					windowmenu.display();
				}
				if (event.key.code == Keyboard::Down)
				{
					menu.Movedown();
					num = menu.RetrieveNumber();
					menu.drawwindow(windowmenu);
					windowmenu.display();
				}
				if (event.key.code == Keyboard::Return)
				{
					switch (num)
					{
					case 0:
					{
							  windowmenu.close();
							  break;
					}
					case 1:
					{
							  booll = true;
							  Difficulty difficulty(windowmenu.getSize().x, windowmenu.getSize().y, number);
							  difficulty.drawwindow(windowmenu);
							  while (windowmenu.isOpen() && booll)
							  {
								  windowmenu.clear(Color::Black);
								  windowmenu.draw(spritemenu);
								  difficulty.drawwindow(windowmenu);
								  windowmenu.display();
								  while (windowmenu.pollEvent(event) && booll)
								  {
									  if (event.type == Event::KeyPressed)
									  {
										  if (event.key.code == Keyboard::Up)
										  {
											  difficulty.Moveupdif();
											  number = difficulty.RetrieveNumber();
										  }
										  if (event.key.code == Keyboard::Down)
										  {
											  difficulty.Movedowndif();
											  number = difficulty.RetrieveNumber();
										  }
										  if (event.key.code == Keyboard::Right)
										  {
											  difficulty.Moveright(windowmenu);
											  number = difficulty.RetrieveNumber();
										  }
										  if (event.key.code == Keyboard::Left)
										  {
											  difficulty.Moveleft(windowmenu);
											  number = difficulty.RetrieveNumber();
										  }
										  if (event.key.code == Keyboard::Return)
										  {
											  number = difficulty.RetrieveNumber();
											  difnum = difficulty.RetrieveSelected();
											  switch (difnum)
											  {
											  case 0:
											  {
														continue;
														break;
											  }
											  case 1:
											  {
														windowmenu.draw(spritemenu);
														menu.drawwindow(windowmenu);
														windowmenu.display();
														booll = false;
														break;
											  }
											  }
										  }
									  }
								  }
							  }
							  break;
					}
					case 2:
					{
							  booll = true;
							  while (windowmenu.isOpen() && booll)
							  {
								  windowmenu.clear(Color::Black);
								  stringstream sw;
								  stringstream sh;
								  windowmenu.draw(spritemenu);
								  options.drawopmenu(windowmenu, myheight, mywidth);
								  windowmenu.display();
								  while (windowmenu.pollEvent(event))
								  {
									  width = options.mazewidth;
									  height = options.mazeheight;
									  if (event.type == Event::KeyPressed)
									  {
										  if (event.key.code == Keyboard::Up)
										  {
											  options.Moveupop();
											  opnum = options.retrieveop();
										  }
										  if (event.key.code == Keyboard::Down)
										  {
											  options.Movedownop();
											  opnum = options.retrieveop();
										  }
										  if (event.key.code == Keyboard::Left)
										  {
											  switch (opnum)
											  {
											  case 0:
											  {
														options.decreasewidth();
														windowmenu.clear(Color::Black);
														sw << options.mazewidth;
														mywidth.setString(sw.str());
														windowmenu.draw(spritemenu);
														options.drawopmenu(windowmenu, myheight, mywidth);
														windowmenu.display();
														break;
											  }
											  case 1:
											  {
														options.decreaseheight();
														windowmenu.clear(Color::Black);
														sh << options.mazeheight;
														myheight.setString(sh.str());
														windowmenu.draw(spritemenu);
														options.drawopmenu(windowmenu, myheight, mywidth);
														windowmenu.display();
														break;
											  }
											  case 2:
											  {
														windowmenu.clear(Color::Black);
														options.Moveleftfow(windowmenu);
														options.drawopmenu(windowmenu, myheight, mywidth);
														fog = options.retrievefow();
														break;
											  }
											  }
										  }
										  if (event.key.code == Keyboard::Right)
										  {
											  switch (opnum)
											  {
											  case 0:
											  {
														options.increasewidth();
														windowmenu.clear(Color::Black);
														sw << options.mazewidth;
														mywidth.setString(sw.str());
														windowmenu.draw(spritemenu);
														options.drawopmenu(windowmenu, myheight, mywidth);
														break;
											  }
											  case 1:
											  {
														options.increaseheight();
														windowmenu.clear(Color::Black);
														sh << options.mazeheight;
														myheight.setString(sh.str());
														windowmenu.draw(spritemenu);
														options.drawopmenu(windowmenu, myheight, mywidth);
														windowmenu.display();
														break;
											  }
											  case 2:
											  {
														windowmenu.clear(Color::Black);
														options.Moverightfow(windowmenu);
														options.drawopmenu(windowmenu, myheight, mywidth);
														fog = options.retrievefow();
														break;
											  }
											  }
										  }
										  if (event.key.code == Keyboard::Return)
										  {
											  booll = false;
											  windowmenu.draw(spritemenu);
											  menu.drawwindow(windowmenu);
											  windowmenu.display();
											  break;
										  }
										  break;
									  }
								  }
							  }
					}
					case 3:
					{
							  break;
					}
					}
					if ((event.key.code == Keyboard::Return) && (num == 3))
					{
						exit(0);
						//return 0;
					}
				}
			}
		}
	}
}