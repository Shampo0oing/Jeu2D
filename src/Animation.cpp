#include "Animation.h"
#include <iostream>

using namespace std;
using namespace sf;

Animation::Animation(int frames, int speed) {
	this->run_right = new Sprite*[frames];
	this->run_left = new Sprite*[frames];
	this->texture = new Texture[frames];
	this->speed = speed;
	this->size = frames;
	this->direction = 1;

	for (int i = 0; i < size; i++) {
		texture[i].loadFromFile("./images/run/adventurer-run-0" + to_string(i) + ".png");
		this->run_right[i] = new Sprite(texture[i]);
		this->run_right[i]->scale(3.0f, 3.0f);

		this->run_left[i] = new Sprite(texture[i]);
		this->run_left[i]->setOrigin({ this->run_left[i]->getLocalBounds().width, 0 });
		this->run_left[i]->setScale({ -3, 3 });
	}

	this->frame = 0;
}

void Animation::render(RenderWindow* rw) {
	if (this->direction == 1)
		rw->draw(*this->run_right[this->frame]);
	else
		rw->draw(*this->run_left[this->frame]);
}

void Animation::tick() {
	if (clock.getElapsedTime().asMilliseconds() >= speed) {
		this->frame++;
		if (this->frame == this->size)
			this->frame = 0;

		this->clock.restart();
	}
}

Sprite* Animation::getCurrentFrame() {
	if (this->direction == 1)
		return this->run_right[this->frame];
	else
		return this->run_left[this->frame];
}

void Animation::setDirection(int d) {
	this->direction = d;
}