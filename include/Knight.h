#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

class Knight
{
private:
	sf::Sprite sprite[6];
	int direction;
	Animation * animation;

public:
	Knight();
	void render(sf::RenderWindow* rw);
};

