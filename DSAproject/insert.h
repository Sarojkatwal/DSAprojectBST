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
		int i = 0;
		float cirrad = 25.0f,width=180.0f,height=180.0f/sqrt(3.0f),x=650.0f,y=20.0f;
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
			show(q, &window,x,y,width,height,1,0,cirrad,ddat,i);
			window.display();
			if (i == 0 || i==1 ||i==2)
			{
				sf::sleep(sf::seconds(1.0f));
			}
			i++;
		}
	}
	void show(bst *q, sf::RenderWindow *window, float x, float y, float width, float height, int initial, int childdir, float cirrad, int ddat,int i)
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
			show(q->left, window, x - width, y + height, width / 10.0f * 7.0f, (width / 10.0f * 7.0f) / sqrt(3.0f), 0, 0, cirrad - 2, ddat,i);
			show(q->right, window, x + width, y + height, width * 7.0f / 10.0f, (width / 10.0f * 7.0f) / sqrt(3.0f), 0, 1, cirrad - 2, ddat,i);
		}
	}
};
