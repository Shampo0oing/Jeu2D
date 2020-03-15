#include "Knight.h"
#include <iostream>
#include "Animation.h"

using namespace std;
using namespace sf;

Knight::Knight(sf::RenderWindow* rw) {
	this->animation = new Animation(6, 200);
	this->moveX = 0;
	this->x = rw->getSize().x / 2.;
	this->y = rw->getSize().y / 2.;
	
}

void Knight::render(RenderWindow* rw) {

	this->animation->getCurrentFrame()->setPosition(this->x, this->y);
	this->animation->render(rw);
}

void Knight::tick() {
	this->animation->tick();
}

void Knight::move(int x, int y, int direction) {
	
	if (x == 0){
		this->animation->setMovement(false);
	}

	else
		this->animation->setMovement(true);

		if (x > 0)
			this->animation->setDirection(1);
		if (x < 0)
			this->animation->setDirection(0);
		

		this->x += x;

}

void Knight::setMoveX(float x) {
	this->moveX = x;
}
//
//void Knight::setX(float x) {
//
//	this->x = x;
//}

int Knight::getX() {
	return this->x;
}

int Knight::getY() {
	return this->y;
}

