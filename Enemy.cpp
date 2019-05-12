#include "Enemy.h"

	Sprite& Enemy::getshape() {
		return shape;
	}
	void Enemy::HPh() {
		HP--;
	}
	int Enemy::getHP() {
		return HP;
	}
	int Enemy::getHPMax() {
		return HPMax;
	}
	void Enemy::Enemymove(float a, float b) {
		shape.move(a, b);
	}
	Enemy::Enemy(Texture *texture, Vector2u windowSize)
	{
		this->HPMax = rand() % 2 + 1;
		this->HP = this->HPMax;

		this->shape.setTexture(*texture);

		this->shape.setScale(0.07f, 0.07f);

		this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand() % (int)(windowSize.y - this->shape.getGlobalBounds().height));
	}

	Enemy::~Enemy() {}

