using namespace std;
class INPUT
{
public:
	int inputs(sf::RenderWindow *window)
	{
		std::ostringstream stri;
		stri.str("");
		window->create(sf::VideoMode(500, 550), "MainMenu", sf::Style::Titlebar | sf::Style::Close);
		while (window->isOpen())
		{
			window->setTitle("Input");
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window->close();
					return -1;
				}
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						//cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
						int x = event.mouseButton.x;
						int y = event.mouseButton.y;
						if ((stri.tellp()) <= 7)
						{
							if (x > 130 && x < 205)
							{
								if (y > 120 && y < 190)
								{
									stri << 1;
								}
								else if (y > 195 && y < 265)
								{
									stri << 4;
								}
								else if (y > 270 && y < 355)
								{
									stri << 7;
								}
							}
							else if (x > 210 && x < 295)
							{
								if (y > 120 && y < 190)
								{
									stri << 2;
								}
								else if (y > 195 && y < 265)
								{
									stri << 5;
								}
								else if (y > 270 && y < 355)
								{
									stri << 8;
								}
								else if (y > 360 && y < 415)
								{
									stri << 0;
								}
								else if (y > 440 && y < 520)
								{
									window->close();
									return returnnumber(stri.str(), stri.tellp());

								}
							}
							else if (x > 300 && x < 380)
							{
								if (y > 120 && y < 190)
								{
									stri << 3;
								}
								else if (y > 195 && y < 265)
								{
									stri << 6;
								}
								else if (y > 270 && y < 355)
								{
									stri << 9;
								}
							}
						}
					}

					if (event.mouseButton.button == sf::Mouse::Right)
					{
						//cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
					}
				}
			}
			window->clear();
			drawSprite(window, "calc.png", sf::Vector2f(126, 120), sf::Vector2f(0.45f, 0.40f));
			drawRectangle(window, sf::Vector2f(255, 73), sf::Color::White, sf::Color::Cyan, sf::Vector2f(130, 30));
			drawSprite(window, "ok.png", sf::Vector2f(210, 445), sf::Vector2f(0.45f, 0.40f));
			drawText(window, 60, sf::Color::Red, sf::Vector2f(135, 30), stri.str());
			window->display();
		}
	}
	void drawRectangle(sf::RenderWindow *window, sf::Vector2f size, sf::Color color1, sf::Color color2, sf::Vector2f position)
	{
		sf::RectangleShape  shape(size);
		shape.setFillColor(color1);
		shape.setPosition(position);
		shape.setOutlineColor(color2);
		shape.setOutlineThickness(5.0f);

		window->draw(shape);
	}
	void drawSprite(sf::RenderWindow *window, std::string ss, sf::Vector2f position, sf::Vector2f S)
	{
		sf::Texture texture;
		texture.loadFromFile(ss);
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setScale(S.x, S.y);
		sprite.setPosition(position);
		window->draw(sprite);
	}
	void drawText(sf::RenderWindow *window, int size, sf::Color color, sf::Vector2f position, string str)
	{
		sf::Font font4text;
		sf::Text nodedata, torder;
		font4text.loadFromFile("roman.ttf");
		nodedata.setFont(font4text);
		nodedata.setFillColor(color);
		nodedata.setPosition(position);
		nodedata.setCharacterSize(size);
		nodedata.setString(str);
		window->draw(nodedata);
	}
	int returnnumber(string ss, int n)
	{
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			k = k * 10 + ss[i] - '0';
		}
		return k;
	}
};