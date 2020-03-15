#include "Animation.h"
#include <iostream>

using namespace std;
using namespace sf;

Animation::Animation(int frames, int speed) {
	this->sprite = new Sprite*[frames];
	this->texture = new Texture[frames];
	this->speed = speed;
	this->size = frames;

	for (int i = 0; i < size; i++) {
		texture[i].loadFromFile("./images/idle/adventurer-idle-0" + to_string(i) + ".png");
		this->sprite[i] = new Sprite(texture[i]);
		this->sprite[i]->scale(3.0f, 3.0f);
		this->sprite[i]->setPosition(0, 0);
	}

	this->frame = 0;
}

void Animation::render(RenderWindow* rw) {
	rw->draw(*this->sprite[this->frame]);
}

void Animation::tick() {
	if (clock.getElapsedTime().asMilliseconds() >= speed) {
		this->frame++;
		if (this->frame == this->size)
			this->frame = 0;

		this->clock.restart();
	}
}