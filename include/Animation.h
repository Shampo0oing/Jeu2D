#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Texture* texture;
	sf::Texture* idle;
	sf::Sprite** run_right;
	sf::Sprite** run_left;
	sf::Sprite** sur_place;
	sf::Clock clock;
	int frame, size, direction, speed;
	bool moving;

public:
	Animation(int frames, int speed);
	void render(sf::RenderWindow* rw);
	void tick();
	sf::Sprite* getCurrentFrame();
	void setDirection(int d);
	void setMovement(bool b);
};