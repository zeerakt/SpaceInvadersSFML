
#include "Bullet.h"


Sprite Bullet::getshape() {
		return shape;
	}

	Bullet::Bullet(Texture *texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);

		this->shape.setScale(0.07f, 0.07f);

		this->shape.setPosition(pos);
	}
	void Bullet::Bulletmove(float a, float b) {
		shape.move(a, b);
	}
	Bullet::~Bullet() {}