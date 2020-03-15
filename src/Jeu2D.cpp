// Jeu2D.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Knight.h"
#include "Animation.h"


using namespace std;
using namespace sf;

int main()
{
    RenderWindow * renderWindow = new RenderWindow(VideoMode(1280, 720), "Jeu 2D");
    Event event;
    Knight knight(renderWindow);
    Clock clock;
    int currentTime = 0, lastTime = clock.getElapsedTime().asMilliseconds();

    while (renderWindow->isOpen()) {
        currentTime = clock.getElapsedTime().asMilliseconds();

        int speed = 3;

        // Close button
        if (renderWindow->pollEvent(event))
            if (event.type == Event::EventType::Closed)
                renderWindow->close();

        if (clock.getElapsedTime().asMilliseconds() >= 17) {
            
			//Keybind et Action
			if (!Keyboard::isKeyPressed(Keyboard::Right) && knight.animation->getDirection() == 1 && !Keyboard::isKeyPressed(Keyboard::Left))
				knight.move(0, 0, knight.animation->getDirection());

			if (!Keyboard::isKeyPressed(Keyboard::Left) && knight.animation->getDirection() == 0 && !Keyboard::isKeyPressed(Keyboard::Right))
				knight.move(0, 0, knight.animation->getDirection());

			//Avancer vers la gauche
			if(Keyboard::isKeyPressed(Keyboard::Left)) {		
				//SPRINT
				if (Keyboard::isKeyPressed(Keyboard::LShift)) 
					knight.move(-speed - 3, 0, knight.animation->getDirection());
				else
					knight.move(-speed, 0, knight.animation->getDirection());
			}

			//Avancer vers la droite
			if(Keyboard::isKeyPressed(Keyboard::Right)) {		

				if (Keyboard::isKeyPressed(Keyboard::LShift)) //SPRINT
					knight.move(speed + 3, 0, knight.animation->getDirection());
				else
					knight.move(speed, 0, knight.animation->getDirection());
			}


            knight.tick();

			clock.restart();
            // Render
            renderWindow->clear();
            knight.render(renderWindow);
            renderWindow->display();
        }
    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
