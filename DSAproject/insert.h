#define PI 3.14159
using namespace std;
struct bst
{
	int data;
	bst *left, *right;
};
class INSERT
{
public:
	void afterinsertion(bst *q,int ddat)
	{
		float cirrad = 15.0f,width=180,height=180/sqrt(3),x=650.0,y=20.0;
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(1300, 750),"Tree after insertion",sf::Style::Default,settings);
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
			show(q, &window,x,y,width,height,1,0,cirrad,ddat);
			window.display();
		}
	}
	void show(bst *q, sf::RenderWindow *window,float x,float y,float width,float height,int initial,int childdir,float cirrad,int ddat)
	{
		float ang;
		sf::CircleShape shape(cirrad);
		shape.setFillColor(sf::Color::White);
		shape.setOutlineThickness(3.0f);
		shape.setOutlineColor(sf::Color::Blue);
		float a = sqrt(pow((width*1.32 - sqrt(2)*cirrad), 2) + pow(((width*1.32) / sqrt(3) - sqrt(2)*cirrad), 2));
		sf::RectangleShape line(sf::Vector2f(a, cirrad/4));
		sf::Font font4text;
		sf::Text nodedata;
		std::ostringstream ddata(ios::ate | ios::out);
		font4text.loadFromFile("roman.ttf");
		nodedata.setFont(font4text);
		nodedata.setCharacterSize(static_cast<int>(cirrad));
		nodedata.setFillColor(sf::Color::Red);
		nodedata.setStyle(sf::Text::Bold);
		nodedata.setPosition(x+cirrad/2, y+cirrad/2.6);
		if (q != NULL)
		{
			ddata << q->data;
			nodedata.setString(ddata.str());
			shape.setPosition(x,y);
			if (q->data == ddat)
			{
				shape.setFillColor(sf::Color::Cyan);
				line.setFillColor(sf::Color::Green);
			}
			if (initial != 1)
			{
				if (childdir == 0)
				{
					line.setPosition(x + sqrt(2.0f)*cirrad+12, y);
					ang = -30;
				}
				else
				{
					line.setPosition(x,y);
					ang = -62-90;
				}
				line.rotate(ang);
				window->draw(line);
			}
			window->draw(shape);
			window->draw(nodedata);
			show(q->left, window, x - width, y + height,width/10*7,(width/10*7)/sqrt(3),0,0,cirrad,ddat);
			show(q->right, window, x + width, y + height,width*7/10,(width/10*7)/sqrt(3),0,1,cirrad,ddat);
		}
	}
};