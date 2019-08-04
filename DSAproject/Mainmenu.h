#include "input.h"
class mainmenu
{
public:
	int draw()
	{
		INPUT AA;
		int x = -1;
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(500, 550), "MainMenu", sf::Style::Titlebar | sf::Style::Close, settings);
		window.setPosition(sf::Vector2i(500, 10));
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					return x;
				}
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						int x = event.mouseButton.x;
						int y = event.mouseButton.y;
						if (x >= 170 && x <= 334)
						{
							if (y > 58 && y < 120)
							{
								window.close();
								return 1;
							}
							else if (y > 177 && y < 233)
							{
								window.close();
								return 2;
							}
							else if (y > 300 && y < 355)
							{
								window.close();
								return 3;
							}
							else if (y > 415 && y < 474)
							{
								window.close();
								return 4;
							}
						}
						//::cout << atan(1)/;
					}
				}
			}
			window.clear(sf::Color::Cyan);
			AA.drawRectangle(&window, sf::Vector2f(400, 500), sf::Color::Green, sf::Color::Yellow, sf::Vector2f(50, 20));
			float y = 20 + 25;
			for (int i = 0; i < 4; i++)
			{
				AA.drawSprite(&window, "oval.png", sf::Vector2f(50 + 80, y), sf::Vector2f(0.1f, 0.1f));
				y = y + 80 + 38;
			}
			AA.drawText(&window, 50, sf::Color::Blue, sf::Vector2f(180, 55), "Insert");
			AA.drawText(&window, 50, sf::Color::Blue, sf::Vector2f(180, 174), "Delete");
			AA.drawText(&window, 50, sf::Color::Blue, sf::Vector2f(178, 293), "Search");
			AA.drawText(&window, 50, sf::Color::Blue, sf::Vector2f(210, 410), "Exit");
			window.display();
		}
	}
};