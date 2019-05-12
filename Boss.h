#pragma once
#include "Enemy.h"
#include "Bullet.h"
class Boss : public Enemy
{
public:	
	Boss(sf::Texture *texture,sf::Vector2u windowSize);
	void HPh();
	std::vector <Bullet> Bbullets;
	virtual ~Boss();
};
