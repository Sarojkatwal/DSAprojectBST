class DELETE
{
public:
	void afterdeletions(bst *q, int ddat,int sdata=-99999,int noofchild=0)
	{
		int i = 0;
		float cirrad = 25.0f, width = 180.0f, height = 180.0f / sqrt(3.0f), x = 650.0f, y = 20.0f;
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(1300, 750), "Deletion Process", sf::Style::Default, settings);
		window.setPosition(sf::Vector2i(10, 10));
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
					}
				}
			}
			window.clear();
			showremovalofnode(q, &window, x, y, width, height, 1, 0, cirrad, ddat, i,sdata,noofchild,q->data);
			window.display();
			if (i == 0 || i==1|| i==2||i==3||i==4)
			{
				sf::sleep(sf::seconds(0.5f));
			}
			i++;
		}
	}
	void showremovalofnode(bst *q, sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad, int ddat, int i,int sdata,int noofchild,int qdata)
	{
		float ang;
		sf::CircleShape shape(cirrad);
		shape.setFillColor(sf::Color::White);
		shape.setOutlineThickness(3.0f);
		shape.setOutlineColor(sf::Color::Blue);
		sf::Font font4text;
		sf::Text nodedata, torder;
		std::ostringstream ddata(ios::ate | ios::out);
		font4text.loadFromFile("roman.ttf");
		nodedata.setFont(font4text);
		nodedata.setCharacterSize(static_cast<int>(cirrad));
		nodedata.setFillColor(sf::Color::Red);
		nodedata.setStyle(sf::Text::Bold);
		if (q != NULL)
		{
			nodedata.setPosition(x + cirrad / 2.0f, y + cirrad / 2.6f);
			float a = sqrt(pow((width*1.3f - sqrt(2.0f)*(cirrad + 2.0f)), 2) + pow(((width*1.30f) / sqrt(3.0f) - sqrt(2.0f)*(cirrad + 2.0f)), 2));
			sf::RectangleShape line(sf::Vector2f(a, cirrad / 4));
			ddata << q->data;
			nodedata.setString(ddata.str());
			shape.setPosition(x, y);
			if (q->data == ddat  &&  q->left==NULL &&  q->right==NULL  && i!=0)
			{
				if (i == 1)
				{
					shape.setOutlineColor(sf::Color::Red);
					shape.setFillColor(sf::Color::Black);
					line.setFillColor(sf::Color::Red);
				}
				else
				{
					shape.setFillColor(sf::Color::Transparent);
					line.setFillColor(sf::Color::Transparent);
					nodedata.setFillColor(sf::Color::Transparent);
					shape.setOutlineColor(sf::Color::Transparent);
				}
			}

			else if ((((q->data == ddat  && q->left != NULL  && q->right != NULL) || q->data == sdata) && i != 0 && noofchild==2))
			{
				if (i == 1)
				{
					if (q->data == ddat)
					{
						shape.setOutlineColor(sf::Color::Red);
						shape.setFillColor(sf::Color::Transparent);
					}
				}
				else if (i == 2)
				{
					if (q->data == ddat)
					{
						shape.setOutlineColor(sf::Color::Red);
						shape.setFillColor(sf::Color::Transparent);
					}
					if (q->data == sdata)
					{
						shape.setOutlineColor(sf::Color::Red);
					}
				}
				else if (i == 3)
				{
					if (q->data == ddat)
					{
						ddata.str("");
						ddata << sdata;
						nodedata.setString(ddata.str());
						shape.setOutlineColor(sf::Color::Red);
					}
					if (q->data == sdata)
					{
						shape.setOutlineColor(sf::Color::Red);
					}
				}
				else if (i == 4)
				{
					if (q->data == ddat)
					{
						ddata.str("");
						ddata << sdata;
						nodedata.setString(ddata.str());
						shape.setOutlineColor(sf::Color::Red);
					}
					if (q->data == sdata)
					{
						shape.setOutlineColor(sf::Color::Green);
						line.setFillColor(sf::Color::Green);
					}
				}
				else
				{
					if (q->data == sdata)
					{
						nodedata.setFillColor(sf::Color::Transparent);
						shape.setOutlineColor(sf::Color::Transparent);
						shape.setFillColor(sf::Color::Transparent);
						line.setFillColor(sf::Color::Transparent);
					}
					ddata.str("");
					ddata << sdata;
					nodedata.setString(ddata.str());
				}
			}

			//
			else if ((((q->data == ddat && (q->left != NULL || q->right != NULL)) || q->data == sdata) && i != 0 && noofchild == 1))
			{
				if (i == 1)
				{
					if (q->data == ddat)
					{
						shape.setOutlineColor(sf::Color::Red);
						shape.setFillColor(sf::Color::Transparent);
					}
				}
				else if (i == 2)
				{
					if (q->data == ddat)
					{
						shape.setOutlineColor(sf::Color::Red);
						shape.setFillColor(sf::Color::Transparent);
					}
					if (q->data == sdata)
					{
						shape.setOutlineColor(sf::Color::Red);
					}
				}
				else if (i == 3)
				{
					if (q->data == ddat)
					{
						shape.setOutlineColor(sf::Color::Red);
						shape.setFillColor(sf::Color::Transparent);
					}
					if (q->data == sdata)
					{
						shape.setOutlineColor(sf::Color::Red);
					}
					line.setFillColor(sf::Color::Red);
				}
				else if (i == 4)
				{
					if (q->data == ddat)
					{
						nodedata.setFillColor(sf::Color::Transparent);
						shape.setFillColor(sf::Color::Transparent);
						shape.setOutlineColor(sf::Color::Transparent);
					}
					if (q->data == sdata)
					{
						shape.setOutlineColor(sf::Color::Green);
					}
					line.setFillColor(sf::Color::Transparent);
				}
				else
				{
					if (q->data == ddat)
					{
						nodedata.setFillColor(sf::Color::Transparent);
						shape.setOutlineColor(sf::Color::Transparent);
						shape.setFillColor(sf::Color::Transparent);
						line.setFillColor(sf::Color::Transparent);
					}
				}
			}
			////
			if (initial != 1)
			{
				if (childdir == 0)
				{
					line.setPosition(x + sqrt(2.0f)*cirrad + 12, y);
					ang = -30;
				}
				else
				{
					line.setPosition(x + 3, y + 3);
					ang = -62 - 90;
				}
				line.rotate(ang);
				window->draw(line);
			}
			window->draw(shape);
			window->draw(nodedata);
			if (q->data == ddat && ddat == qdata && i>4 && noofchild==1)
			{
				initial = 1;
			}
			else
			{
				initial = 0;
			}
			if (i>4 && ((noofchild==1 && q->data==ddat)|| (noofchild == 2 && q->data == sdata)))
			{
				showremovalofnode(q->left, window, x, y  , width , width / sqrt(3.0f), initial, childdir, cirrad , ddat, i, sdata, noofchild,qdata);
				showremovalofnode(q->right, window, x, y , width , width / sqrt(3.0f), initial, childdir, cirrad, ddat, i, sdata, noofchild,qdata);
			}
			else
			{
				showremovalofnode(q->left, window, x - width, y + height, width / 10.0f * 7.0f, (width / 10.0f * 7.0f) / sqrt(3.0f), initial, 0, cirrad - 2, ddat, i, sdata, noofchild,qdata);
				showremovalofnode(q->right, window, x + width, y + height, width * 7.0f / 10.0f, (width / 10.0f * 7.0f) / sqrt(3.0f), initial, 1, cirrad - 2, ddat, i, sdata, noofchild,qdata);
			}
		}
	}
};