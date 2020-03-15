#include "Animation.h"
#include <iostream>

using namespace std;
using namespace sf;

Animation::Animation(int frames) {
	this->sprite = new Sprite*[frames];
	Texture texture;

	for (int i = 0; i < frames; i++) {
		texture.loadFromFile("images/adventurer-run-0" + to_string(i) + ".png");
		this->sprite[i] = new Sprite(texture);
		this->sprite[i]->scale(3.0f, 3.0f);
		this->sprite[i]->setPosition(0, 0);
	}

	this->frame = 0;
}

void Animation::render(RenderWindow* rw) {
	rw->draw(*(this->sprite[this->frame]));
}

void Animation::tick() {
	this->frame = (this->frame + 1) % this->frame;
}