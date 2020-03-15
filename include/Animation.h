#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Texture* texture;
	sf::Sprite** sprite;
	sf::Clock clock;
	int frame, size;
	int speed;

public:
	Animation(int frames, int speed);
	void render(sf::RenderWindow* rw);
	void tick();
};

