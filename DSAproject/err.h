class EMPTYOREXISTS
{
public:
	void showerr(std::string str)
	{
		INPUT AA;
		sf::RenderWindow window(sf::VideoMode(280, 240), str);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			AA.drawSprite(&window,"error.png" ,sf::Vector2f(50, 50),sf::Vector2f(0.3f,0.3f));
			window.display();
		}
	}
};