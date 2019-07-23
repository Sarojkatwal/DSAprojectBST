class ORDER
{
public:
	void order(bst *q,int n)
	{
		float cirrad = 25.0f, width = 180.0f, height = 180.0f / sqrt(3.0f), x = 650.0f, y = 50.0f;
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(1300, 750), "Tree traversal", sf::Style::Default, settings);
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
						//cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
					}
				}
			}
			window.clear();
			show(q, &window, x, y, width, height, 1, 0, cirrad, 999999,"");
			window.display();
			if (n == 1)
			{
				animatepreorder(q, q, &window, x, y, width, height, 1, 0, cirrad);
			}
			else if(n == 2)
			{
				animatepostorder(q, q, &window, x, y, width, height, 1, 0, cirrad);
			}
			else
			{
				animateinorder(q, q, &window, x, y, width, height, 1, 0, cirrad);
			}
			sf::sleep(sf::seconds(5));
			window.close();
		}
	}
	void show(bst *q, sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad, int ddat,string str)
	{
		float ang;
		sf::CircleShape shape(cirrad);
		shape.setFillColor(sf::Color::White);
		shape.setOutlineThickness(3.0f);
		shape.setOutlineColor(sf::Color::Blue);
		sf::Font font4text;
		sf::Text nodedata,torder;
		std::ostringstream ddata(ios::ate | ios::out);
		font4text.loadFromFile("roman.ttf");
		nodedata.setFont(font4text);
		nodedata.setCharacterSize(static_cast<int>(cirrad));
		nodedata.setFillColor(sf::Color::Red);
		nodedata.setStyle(sf::Text::Bold);
		torder.setFont(font4text);
		torder.setCharacterSize(70);
		torder.setFillColor(sf::Color::White);
		torder.setPosition(10,2);
		torder.setString(str);
		window->draw(torder);
		if (q != NULL)
		{
			nodedata.setPosition(x + cirrad / 2.0f, y + cirrad / 2.6f);
			float a = sqrt(pow((width*1.3f - sqrt(2.0f)*(cirrad+2.0f)), 2) + pow(((width*1.30f) / sqrt(3.0f) - sqrt(2.0f)*(cirrad+2.0f)), 2));
			sf::RectangleShape line(sf::Vector2f(a, cirrad / 4));
			ddata << q->data;
			nodedata.setString(ddata.str());
			shape.setPosition(x, y);
			if (q->data == ddat)
			{
				shape.setFillColor(sf::Color::Green);
				nodedata.setFillColor(sf::Color::White);
			}
			if (initial != 1)
			{
				if (childdir == 0)
				{
					line.setPosition(x + sqrt(2.0f)*cirrad + 12, y);
					ang = -30;
				}
				else
				{
					line.setPosition(x+3, y+3);
					ang = -62 - 90;
				}
				line.rotate(ang);
				window->draw(line);
			}
			window->draw(shape);
			window->draw(nodedata);
			show(q->left, window, x - width, y + height, width / 10.0f * 7.0f, (width / 10.0f * 7.0f) / sqrt(3.0f), 0, 0, cirrad - 2, ddat, str);
			show(q->right, window, x + width, y + height, width * 7.0f / 10.0f, (width / 10.0f * 7.0f) / sqrt(3.0f), 0, 1, cirrad-2, ddat,str);
		}
	}
	void animatepreorder(bst *q,bst *root ,sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad)
	{
		if (q != NULL)
		{
			show(root, window, x, y, width, height, 1, 0, cirrad, q->data,"Traversing Preorder");
			window->display();
			sf::sleep(sf::seconds(3));
			animatepreorder(q->left,root, window, x, y, width, height, 1, 0, cirrad);
			animatepreorder(q->right,root, window, x, y, width, height, 1, 0, cirrad);
		}
	}
	void animatepostorder(bst *q, bst *root, sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad)
	{
		if (q != NULL)
		{
			animatepostorder(q->left, root, window, x, y, width, height, 1, 0, cirrad);
			animatepostorder(q->right, root, window, x, y, width, height, 1, 0, cirrad);
			show(root, window, x, y, width, height, 1, 0, cirrad, q->data,"Traversing Postorder");
			window->display();
			sf::sleep(sf::seconds(3));
		}
	}
	void animateinorder(bst *q, bst *root, sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad)
	{
		if (q != NULL)
		{
			animateinorder(q->left, root, window, x, y, width, height, 1, 0, cirrad);
			show(root, window, x, y, width, height, 1, 0, cirrad, q->data, "Traversing Inorder");
			window->display();
			sf::sleep(sf::seconds(3));
			animateinorder(q->right, root, window, x, y, width, height, 1, 0, cirrad);
		}
	}
};