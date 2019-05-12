#include "Player.h"

	Sprite Player::getshape() {
		return shape;
	}
	void Player::HPh() {
		HP--;
	}
	std::vector<Bullet> bullets;
	int Player::getHP() {
		return HP;
	}
	int Player::getHPMax() {
		return HPMax;
	}
	void Player::PlayerMove(float a, float b) {
		shape.move(a, b);

	}

	Player::Player(Texture *texture)
	{
		this->HPMax = 10;
		this->HP = this->HPMax;

		this->texture = texture;
		this->shape.setTexture(*texture);

		this->shape.setScale(0.1f, 0.1f);
	}
	void Player::SetPositionTop(RenderWindow &window) {
		shape.setPosition(shape.getPosition().x, 0.f);
	}
	void Player::SetPositionBottom(RenderWindow &window) {
		shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getGlobalBounds().height);
	}
	void Player::SetPositionLeft(RenderWindow &window) {
		shape.setPosition(0.f, shape.getPosition().y);
	}
	void Player::SetPositionRight(RenderWindow &window) {
		shape.setPosition(window.getSize().x - shape.getGlobalBounds().width, shape.getPosition().y);
	}
	Player::~Player() {}




