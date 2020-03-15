#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

class Knight
{
private:
	int x, y, moveX;

public:
	Knight(sf::RenderWindow* rw);
	Animation* animation;
	void render(sf::RenderWindow* rw);
	void tick();
	void move(int x, int y, int direction);
	void setMoveX(float x);
	int getX();
	int getY();
};

