#pragma once 

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace sf;

class Enemy
{
protected:
	Sprite shape;
	int HP;
	int HPMax;
public:
	Enemy();
	Enemy(sf::Texture *texture, sf::Vector2u windowSize);
	 Sprite &getshape();
	virtual void HPh();
	 int getHP();
	int getHPMax();
	void Enemymove(float a, float b);
	virtual ~Enemy();
};
