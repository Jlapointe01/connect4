#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>   //Changer pour list.hpp
#include <vector> //changer pour vector.hpp


//Postion coin en bas a gauche : 67 ,940
//Difference haut et bas : 175 px 
//Difference gauche et droite : 174 px

struct point {
	int x;
	int y;
	point(int x1, int y1) {
		x = x1;
		y = y1;
	}
};


using namespace sf;
using namespace std;

void left(CircleShape &triangle, point &posTriangle);
void right(CircleShape &triangle, point &posTriangle);
void positionMouse(CircleShape &triangle, int &x, int y);
void insererJeton(vector<list<int>> &grille, list<int>::iterator& it);

int main()
{

	point posTriangle(150, 60);
	RenderWindow window(sf::VideoMode(1278, 1106), "Connect 4");
	CircleShape shape(50.f);
	CircleShape triangle(35, 3);
	Texture map;

	list<int>::iterator it[7];
	vector<list<int>> _grille(7, list<int>());

	//Initialisation des pointeurs
	for (int i = 0; i < 7; i++) {
		it[i] = _grille[i].begin();
	}

	if (!map.loadFromFile("Connect4_map.png"))
		cout << "Erreur";

	Sprite _map(map);
	shape.setFillColor(sf::Color::Red);

	shape.setPosition(Vector2f(241, 765));

	triangle.setFillColor(Color::Red);
	triangle.setPosition(Vector2f(posTriangle.x, posTriangle.y));
	triangle.rotate(180);
	// 1278 pixels x 1106 pixels

	while (window.isOpen()) {
		Event event;
		Event keyPressed;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case Keyboard::Right:
					if (posTriangle.x == 1200)
					{
						right(triangle, posTriangle);
						posTriangle.x = 150;
					}
					else
					{
						right(triangle, posTriangle);
						posTriangle.x += 175;
					}
					break;
				case Keyboard::Left:
					if (posTriangle.x == 150)
					{
						left(triangle, posTriangle);
						posTriangle.x = 1200;
					}
					else
					{
						left(triangle, posTriangle);
						posTriangle.x -= 175;
					}
					break;
				case Keyboard::Return:
					//fonction placer jeton		
					break;
				}
			}
			//if (event.type == sf::Event::MouseMoved)
			//{
			//	positionMouse(triangle, event.mouseMove.x, posTriangleY);//puisqu'on veut que le triangle reste en haut
			//}
		}


		window.clear();
		window.draw(_map);
		window.draw(shape);
		window.draw(triangle);
		window.display();
	}
	return 0;
}

void left(CircleShape &triangle, point &posTriangle)
{
	if (posTriangle.x == 150)
	{
		posTriangle.x = 1200;
		triangle.setPosition(Vector2f(posTriangle.x, posTriangle.y));
	}
	else
	{
		triangle.setPosition(Vector2f(posTriangle.x - 175, posTriangle.y));
	}
}


void right(CircleShape &triangle, point &posTriangle) {
	if (posTriangle.x == 1200)
	{
		posTriangle.x = 150;
		triangle.setPosition(Vector2f(posTriangle.x, posTriangle.y));
	}
	else
	{
		triangle.setPosition(Vector2f(posTriangle.x + 175, posTriangle.y));
	}
}

void positionMouse(CircleShape &triangle, int &x, int y)
{
	triangle.setPosition(Vector2f(x, y));
}

void insererJeton(vector<list<int>> &grille, list<int>::iterator& it) 
{



}