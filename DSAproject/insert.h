#include "Search.h"
#define PI 3.14159
using namespace std;
class INSERT
{
public:
	SEARCH ss;
	void afterinsertion(sf::RenderWindow *window,bst *q,int ddat,int n)
	{
		int i = 0;
		float cirrad = 25.0f,width=180.0f,height=180.0f/sqrt(3.0f),x=650.0f,y=20.0f;
		while (window->isOpen())
		{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
					}
				}
			}
			window->clear();
			if (n == 1)
			{
				show(q, window, x, y, width, height, 1, 0, cirrad, ddat, i);
				window->display();
				if (i > 5)
				{
					window->close();
					return;
				}
			}
			else if(n==0)
			{
				window->clear();
				ss.show(q, window, x, y, width, height, 1, 0, cirrad, 999999, "", ddat);
				window->display();
				ss.animatesearch(q, q, window, x, y, width, height, 1, 0, cirrad,ddat, 1);
				return;
			}
			if( (i == 0 || i==1 ||i==2||i==3||i==4||i==5) && n!=0)
			{
				sf::sleep(sf::seconds(1.0f));
			}
			i++;
		}
	}
	void show(bst *q, sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad, int ddat,int i)
	{
		float ang=atan((0.54f*(height+5))/width)/ 0.01745329252;
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
			nodedata.setPosition(x + cirrad / (q->data / 100 >= 1 ? cirrad/3 : 2.0f), y + cirrad / 2.6f);
			float a = sqrt(pow((width/0.54f - sqrt(2.0f)*(cirrad + 2.0f)-8.0f), 2) + pow((height- sqrt(2.0f)*(cirrad + 2.0f)), 2));
			a = ang >= 60 ? a - a / 25 : a;
			a = ang >= 70 ? a - a / 7 : a;
			sf::RectangleShape line(sf::Vector2f(a, cirrad / 4));
			ddata << q->data;
			nodedata.setString(ddata.str());
			shape.setPosition(x, y);
			if (q->data == ddat)
			{
				if(i==0)
				{
					shape.setFillColor(sf::Color::Transparent);
					line.setFillColor(sf::Color::Transparent);
					nodedata.setFillColor(sf::Color::Transparent);
					shape.setOutlineColor(sf::Color::Transparent);
				}
				else if (i == 1)
				{
					shape.setFillColor(sf::Color::Transparent);
					line.setFillColor(sf::Color::Transparent);
					nodedata.setFillColor(sf::Color::Transparent);
				}
				else if (i == 2)
				{
					shape.setFillColor(sf::Color::Green);
					line.setFillColor(sf::Color::Transparent);
				}
				else
				{
					shape.setFillColor(sf::Color::Green);
					line.setFillColor(sf::Color::Cyan);
				}
				i = 100;
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
					line.setPosition(x + sqrt(2.0f)*cirrad +kkk, y-mm);
					ang = -ang;
				}
				else
				{
					float kk = 4.0f;
					if (ang > 60)
					{
						kk =8.0f;
					}
					line.setPosition(x + kk, y);
					ang = -180 + ang;
				}
				line.rotate(ang);
				window->draw(line);
			}
			window->draw(shape);
			window->draw(nodedata);
			show(q->left, window, x - width, y + height, width *0.54f, height-5.0f, 0, 0, cirrad - 2, ddat,i);
			show(q->right, window, x + width, y + height, width *0.54f, height-5.0f, 0, 1, cirrad - 2, ddat,i);
		}
	}
};
