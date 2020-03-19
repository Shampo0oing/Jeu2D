#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <map>
#include "ImageLoader.h"
#include "Character.h"

using namespace std;
using namespace sf;

int main() {

	RenderWindow* rw = new RenderWindow(VideoMode(1280, 720), "Jeu2D");
	rw->setKeyRepeatEnabled(false);
	Event event;
	Character c("../assets/images/knight", 0, 0);
	Clock clock;

	while (rw->isOpen()) {

		while (rw->pollEvent(event)) {

			if (event.type == Event::EventType::Closed)
				rw->close();

		}


		if (clock.getElapsedTime().asMilliseconds() >= 17) { // 60 fps

			if (!Keyboard::isKeyPressed(Keyboard::X) && !Keyboard::isKeyPressed(Keyboard::Right)) {
				c.selectAnimation("idle");
			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				c.move(3, 0);
			}

			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				c.move(-3, 0);
			}

			if (Keyboard::isKeyPressed(Keyboard::X)) {
				c.selectAnimation("attack");
			}

			rw->clear();

			// Render game
			c.render(rw);

			rw->display();

			clock.restart();
		}

		c.tick();
	}



}