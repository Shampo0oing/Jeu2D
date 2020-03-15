#include "Animation.h"
#include <iostream>

using namespace std;
using namespace sf;

Animation::Animation(int frames, int speed) {
	this->run_right = new Sprite*[frames];
	this->run_left = new Sprite*[frames];
	this->sur_place_droite = new Sprite* [frames];
	this->sur_place_gauche = new Sprite * [frames];
	this->texture = new Texture[frames];
	this->idle = new Texture[frames];
	this->speed = speed;
	this->size = frames;
	this->direction = 1;
	this->moving = false;
	this->regardeDroite = true;

	for (int i = 0; i < size; i++) {
		texture[i].loadFromFile("D:/document/Jeu2D/images/run/adventurer-run-0" + to_string(i) + ".png");
		this->run_right[i] = new Sprite(texture[i]);
		this->run_right[i]->scale(3.0f, 3.0f);

		this->run_left[i] = new Sprite(texture[i]);
		this->run_left[i]->setOrigin({ this->run_left[i]->getLocalBounds().width, 0 });
		this->run_left[i]->setScale({ -3, 3 });

		idle[i].loadFromFile("D:/document/Jeu2D/images/idle/adventurer-idle-0" + to_string(i) + ".png");
		this->sur_place_droite[i] = new Sprite(idle[i]);
		this->sur_place_droite[i]->scale(3.0f, 3.0f);

		this->sur_place_gauche[i] = new Sprite(idle[i]);
		this->sur_place_gauche[i]->setOrigin({ this->sur_place_gauche[i]->getLocalBounds().width, 0 });
		this->sur_place_gauche[i]->setScale({ -3, 3 });


	}

	this->frame = 0;
}
Animation::~Animation() {
	for (int i = 0; i < size; i++) {

		this->run_right[i];
		this->run_left[i];
		this->sur_place_droite[i];
		this->sur_place_gauche[i];
	}

	delete[]run_right;
	delete[]run_left;
	delete[]sur_place_droite;
	delete[]sur_place_gauche;

	delete texture;
	delete idle;
}

void Animation::render(RenderWindow* rw) {

	if (moving == false) {
		if (direction == 1)
			rw->draw(*this->sur_place_droite[this->frame]);

		else
			rw->draw(*this->sur_place_gauche[this->frame]);

		this->size = 3;
	}
	else
		if (this->direction == 1 )
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
	if (moving == false) {

		if(direction == 1)
			return this->sur_place_droite[this->frame];
		else
			return this->sur_place_gauche[this->frame];

	}

	else
		if (this->direction == 1 )
			return this->run_right[this->frame];
		else
			return this->run_left[this->frame];
}

void Animation::setDirection(int d) {
	this->direction = d;
}

void Animation::setMovement(bool b) {
	this->moving = b;
}

int Animation::getDirection() {

	return direction;
}
