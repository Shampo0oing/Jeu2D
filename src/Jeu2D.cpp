// Jeu2D.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void Deplacement();

int main(int argc, char** argv)
{	
	void Deplacement();
    RenderWindow renderWindow(VideoMode(1280, 720), "Jeu 2D");
	Event event;
	Clock clock;
	Texture perso;
	perso.loadFromFile("images/adventurer-run-00.png");
	Sprite sprite(perso);
	sprite.setScale(3.0f, 3.0f);

    while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event))
			if (event.type == Event::EventType::Closed)
				renderWindow.close();

			else if (event.type == Event::EventType::KeyPressed)
				Deplacement();

		//cout << clock.getElapsedTime().asMicroseconds() << endl;
		
		renderWindow.clear();
		renderWindow.draw(sprite);
        renderWindow.display();
    }

}

void Deplacement() {

	if(Keyboard::isKeyPressed(Keyboard::Right))
		cout << "Le MC bouge vers la droite" << endl;

	else if (Keyboard::isKeyPressed(Keyboard::Left))
		cout << "Le MC bouge vers la gauche" << endl;

	else if (Keyboard::isKeyPressed(Keyboard::Down))
		cout << "Le MC crouch" << endl;

	else if(Keyboard::isKeyPressed(Keyboard::Up))
		cout << "Le MC monte ou saute" << endl;

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
