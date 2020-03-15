#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Texture* texture;
	sf::Texture* idle;
	sf::Sprite** run_right;
	sf::Sprite** run_left;
	sf::Sprite** sur_place_droite;
	sf::Sprite** sur_place_gauche;
	sf::Clock clock;
	int frame, size, direction, speed;
	bool moving, regardeDroite;

public:
	Animation(int frames, int speed);
	~Animation();
	void render(sf::RenderWindow* rw);
	void tick();
	sf::Sprite* getCurrentFrame();
	void setDirection(int d);
	int getDirection();
	void setMovement(bool b);
};