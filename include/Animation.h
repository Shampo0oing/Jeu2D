#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Sprite** sprite;
	int frame;

public:
	Animation(int frames);
	void render(sf::RenderWindow* rw);
	void tick();
};

