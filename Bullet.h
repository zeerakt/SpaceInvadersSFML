#pragma once 

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace sf;
class Bullet {
protected:
	Sprite shape;
public:
	Sprite getshape();

	Bullet(Texture *texture, Vector2f pos);


	void Bulletmove(float a, float b);

	~Bullet();
};
