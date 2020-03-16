#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <map>
#include <iterator>
#include "ImageLoader.h"
using namespace std;
using namespace sf;

int main() {

	RenderWindow* rw = new RenderWindow(VideoMode(1280, 720), "Jeu2D");
	Event event;
	Sprite* sprite;

	while (rw->isOpen()) {

		if (rw->pollEvent(event))
			if (event.type == Event::EventType::Closed)
				rw->close();
		
		sprite = ImageLoader::LoadImage("../assets/images/idle/adventurer-idle-02.png");



		rw->clear();
		rw->draw(*sprite);
		rw->display();
	}



}