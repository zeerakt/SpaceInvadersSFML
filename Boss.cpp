#include "Boss.h"


Boss::Boss(sf::Texture *texture, sf::Vector2u windowSize) : Enemy(texture,windowSize)
{
	this->HPMax = 10;
	this->HP = this->HPMax;

	this->shape.setTexture(*texture);

	this->shape.setScale(0.1f, 0.1f);

	this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand() % (int)(windowSize.y - this->shape.getGlobalBounds().height));
}

std::vector<Bullet> Bbullets;
void Boss::HPh() {
	HP = HP - 1 ;
}

Boss::~Boss()
{}
