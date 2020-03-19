#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <map>
#include "ImageLoader.h"
#include "Character.h"

using namespace std;
using namespace sf;

int main() {

	RenderWindow* rw = new RenderWindow(VideoMode(1920, 1080), "Jeu2D");
	rw->setKeyRepeatEnabled(false);
	Event event;
	Character c("../assets/images/knight", rw->getSize().x / 2, rw->getSize().y * 95/100, 6.f);
	Clock clock;
	Sprite* bg = ImageLoader::LoadImage("../assets/images/background.png");
	bg->setScale(rw->getSize().x / bg->getLocalBounds().width, rw->getSize().y / bg->getLocalBounds().height );

	Character troll("../assets/images/troll", rw->getSize().x / 1.5, rw->getSize().y * 95/100, 0.4f);

	while (rw->isOpen()) {

		while (rw->pollEvent(event)) {

			if (event.type == Event::EventType::Closed)
				rw->close();
		}

		if (clock.getElapsedTime().asMilliseconds() >= 17) { // 60 fps

			c.tick();
			troll.tick();

			if (!Keyboard::isKeyPressed(Keyboard::X) && !Keyboard::isKeyPressed(Keyboard::Right)) {
				troll.selectAnimation("idle");
			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				troll.move(5, 0);
			}

			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				troll.move(-5, 0);
			}

			if (Keyboard::isKeyPressed(Keyboard::X)) {
				troll.selectAnimation("attack");
			}

			rw->clear();

			// Render game
			rw->draw(*bg);
			
			troll.render(rw);
			c.render(rw);

			rw->display();

			clock.restart();
		}
	}



}