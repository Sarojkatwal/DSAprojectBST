using namespace std;
struct bst
{
	int data;
	bst *left, *right;
};
class SEARCH
{
public:
	void search(bst *q,int num)
	{
		float cirrad = 25.0f, width = 180.0f, height = 180.0f / sqrt(3.0f), x = 650.0f, y = 50.0f;
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(1300, 750), "Searching", sf::Style::Default, settings);
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
			show(q, &window, x, y, width, height, 1, 0, cirrad, 999999, "",num);
			window.display();
			animatesearch(q, q, &window, x, y, width, height, 1, 0, cirrad,num,0);
			sf::sleep(sf::seconds(5));
			window.close();
		}
	}
	void show(bst *q, sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad, int ddat, string str,int num)
	{
		float ang = atan((0.54f*(height +5)) / width) / 0.01745329252;
		sf::CircleShape shape(cirrad);
		shape.setFillColor(sf::Color::White);
		shape.setOutlineThickness(3.0f);
		shape.setOutlineColor(sf::Color::Blue);
		sf::Font font4text;
		sf::Text nodedata, torder;
		std::ostringstream ddata;
		font4text.loadFromFile("roman.ttf");
		nodedata.setFont(font4text);
		nodedata.setCharacterSize(static_cast<int>(cirrad));
		nodedata.setFillColor(sf::Color::Red);
		nodedata.setStyle(sf::Text::Bold);
		torder.setFont(font4text);
		torder.setCharacterSize(30);
		torder.setFillColor(sf::Color::White);
		torder.setPosition(10, 2);
		if (q != NULL)
		{
			torder.setString(str);
			window->draw(torder);

			nodedata.setPosition(x + cirrad / (q->data / 100 >=1? cirrad / 3 : 2.0f), y + cirrad / 2.6f);
			float a = sqrt(pow((width / 0.54f - sqrt(2.0f)*(cirrad + 2.0f) - 8.0f), 2) + pow((height - sqrt(2.0f)*(cirrad + 2.0f)), 2));
			a = ang >= 60 ? a - a / 25 : a;
			a = ang >= 70 ? a - a /7 : a;
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
					float kkk = 8.0f;
					float mm = 0.0f;
					if (ang > 60)
					{
						kkk = 0;
						mm = 3.0f;
					}
					line.setPosition(x + sqrt(2.0f)*cirrad + kkk, y - mm);
					ang = -ang;
				}
				else
				{
					float kk = 4.0f;
					if (ang > 60)
					{
						kk = 8.0f;
					}
					line.setPosition(x + kk, y);
					ang = -180 + ang;
				}
				line.rotate(ang);
				window->draw(line);
			}
			window->draw(shape);
			window->draw(nodedata);
			show(q->left, window, x - width, y + height, width *0.54f, height-5, 0, 0, cirrad - 2, ddat, str,num);
			show(q->right, window, x + width, y + height, width *0.54f, height-5, 0, 1, cirrad - 2, ddat, str,num);
		}
	}
	void animatesearch(bst *q, bst *root, sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad,int num,int forinsert)
	{
			std::ostringstream ostr;
			if (q != NULL)
			{
				if (q->data == num)
				{
					ostr.str("");
					if (forinsert == 0)
					{
						ostr << "Data Found";
					}
					else
					{
						ostr << "Data Already present.\nSame data cannot be entered twice.";
					}
				}
				else if (q->data < num)
				{
					ostr.str("");
					ostr << q->data << " less than " << num << " (num)\nSo check it's right child";
				}
				else
				{
					ostr.str("");
					ostr << q->data << " greater than " << num << " (num)\nSo check it's left child";
				}
				show(root, window, x, y, width, height, 1, 0, cirrad, q->data, ostr.str(), num);
				window->display();
				sf::sleep(sf::seconds(4));
				window->clear();
				if (q->data == num)
				{
					window->close();
					return;
				}
				else if (q->data > num)
				{
					animatesearch(q->left, root, window, x, y, width, height, 1, 0, cirrad,num,forinsert);
				}
				else
				{
					animatesearch(q->right, root, window, x, y, width, height, 1, 0, cirrad,num, forinsert);
				}	
			}
			else
			{
				if (forinsert == 0)
				{
					show(root, window, x, y, width, height, 1, 0, cirrad, -99999999, "Data not found.", num);
					window->display();
					sf::sleep(sf::seconds(3));
					window->clear();
				}
				else
				{
					show(root, window, x, y, width, height, 1, 0, cirrad, -99999999, "Null node.Insert Data here.", num);
					window->display();
					sf::sleep(sf::seconds(3));
					return;
				}
			}
	}
};