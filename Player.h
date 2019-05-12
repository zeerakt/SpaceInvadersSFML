#pragma once 

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Bullet.h"


using namespace sf;
class Player
{
private:
	Sprite shape;
	Texture *texture;
	int HP;
	int HPMax;

public:
	Sprite getshape();
	void HPh();
	std::vector<Bullet> bullets;
	int getHP();
	int getHPMax();
	void PlayerMove(float a, float b);
	Player(Texture *texture);
	void SetPositionTop(RenderWindow &window);
	void SetPositionBottom(RenderWindow &window);
	void SetPositionLeft(RenderWindow &window);
	void SetPositionRight(RenderWindow &window);
	~Player();
};
