#include <iostream>
#include "Deplacement.h"
using namespace sf;
using namespace std;

void FaireDeplacement() {

	if (Keyboard::isKeyPressed(Keyboard::Right))
		cout << "Le MC bouge vers la droite" << endl;

	else if (Keyboard::isKeyPressed(Keyboard::Left))
		cout << "Le MC bouge vers la gauche" << endl;

	else if (Keyboard::isKeyPressed(Keyboard::Down))
		cout << "Le MC crouch" << endl;

	else if (Keyboard::isKeyPressed(Keyboard::Up))
		cout << "Le MC monte ou saute" << endl;

}