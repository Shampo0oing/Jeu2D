// Jeu2D.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Deplacement.h"

using namespace sf;
using namespace std;


int main(int argc, char** argv)
{	
    RenderWindow renderWindow(VideoMode(1280, 720), "Jeu 2D");
	Event event;
	Clock clock;
	Texture perso;
	perso.loadFromFile("D:/Document/Jeu2D/images/adventurer-run-00.png");
	Sprite sprite(perso);
	sprite.setScale(3.0f, 3.0f);
	
    while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event))
			if (event.type == Event::EventType::Closed)
				renderWindow.close();

			else if (event.type == Event::EventType::KeyPressed)
				FaireDeplacement();

		//cout << clock.getElapsedTime().asMicroseconds() << endl;
		
		renderWindow.clear();
		renderWindow.draw(sprite);
        renderWindow.display();
    }

}

