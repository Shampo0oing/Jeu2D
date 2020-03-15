#include "Knight.h"
#include <iostream>
#include "Animation.h"

using namespace std;
using namespace sf;

Knight::Knight() {
	this->animation = new Animation(6, 200);
	this->moveX = 0;
	this->x = 0;
	this->y = 0;
	
}

void Knight::render(RenderWindow* rw) {

	this->animation->getCurrentFrame()->setPosition(this->x, this->y);
	this->animation->render(rw);
}

void Knight::tick() {
	this->animation->tick();
}

void Knight::move(int x, int y) {
	
	if (x == 0)
		this->animation->setMovement(false);

	else
		this->animation->setMovement(true);

		if (x > 0)
			this->animation->setDirection(1);
		if (x < 0)
			this->animation->setDirection(0);
		

		this->x += x;

}

void Knight::setMoveX(int x) {
	this->moveX = x;
}

int Knight::getX() {
	return this->x;
}

int Knight::getY() {
	return this->y;
}

