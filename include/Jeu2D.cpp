#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <map>
#include <iterator>
#include "ImageLoader.h"
#include "Animation.h"
using namespace std;
using namespace sf;

int main() {

	RenderWindow* rw = new RenderWindow(VideoMode(1280, 720), "Jeu2D");
	Event event;
	Sprite* sprite;
	Animation a("../assets/images/idle", 200, false);
	Clock clock;

	while (rw->isOpen()) {

		if (rw->pollEvent(event))
			if (event.type == Event::EventType::Closed)
				rw->close();
		
		 //augmente le nombres de frames


		if (clock.getElapsedTime().asMilliseconds() >= 17) {

			rw->clear();

			a.render(rw); //Affiche les sprites

			rw->display();

			clock.restart();

		}

		a.tick();

	}



}