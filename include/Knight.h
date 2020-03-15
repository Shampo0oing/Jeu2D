#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

class Knight
{
private:
	Animation * animation;
	int x, y, moveX;

public:
	Knight();
	void render(sf::RenderWindow* rw);
	void tick();
	void move(int x, int y);
	void setMoveX(int x);
	int getX();
	int getY();
};

