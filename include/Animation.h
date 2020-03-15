#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Texture* texture;
	sf::Sprite** run_right;
	sf::Sprite** run_left;
	sf::Clock clock;
	int frame, size, direction, speed;

public:
	Animation(int frames, int speed);
	void render(sf::RenderWindow* rw);
	void tick();
	sf::Sprite* getCurrentFrame();
	void setDirection(int d);

};