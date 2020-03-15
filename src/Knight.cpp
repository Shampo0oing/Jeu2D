#include "Knight.h"
#include <iostream>
#include "Animation.h"

using namespace std;
using namespace sf;

Knight::Knight() {
	this->animation = new Animation(3, 200);
	this->direction = 0;
}

void Knight::render(RenderWindow* rw) {
	this->animation->render(rw);
}

void Knight::tick() {
	this->animation->tick();
}