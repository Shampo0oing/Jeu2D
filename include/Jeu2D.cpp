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
	Character c("../assets/images/knight");
	Clock clock;

	while (rw->isOpen()) {

		while (rw->pollEvent(event)) {

			if (event.type == Event::EventType::Closed)
				rw->close();



			if (Keyboard::isKeyPressed(Keyboard::X)) {
				c.selectAnimation("attack");
			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				c.selectAnimation("run");
			}

			if(!Keyboard::isKeyPressed(Keyboard::X) && !Keyboard::isKeyPressed(Keyboard::Right))
				c.selectAnimation("idle");


		}
		
			//augmente le nombres de frames


		if (clock.getElapsedTime().asMilliseconds() >= 17) {




			rw->clear();

			c.render(rw); //Affiche les sprites

			rw->display();

			clock.restart();


		}



		c.tick();




	}



}