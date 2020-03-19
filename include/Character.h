#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>

class Character {

public:
	Character(const std::string& path, int x, int y);
	void render(sf::RenderWindow* rw);
	void tick();
	void selectAnimation(const std::string& name);
	void move(int x, int y);



private:
	std::map<std::string, Animation*> animations_;
	std::string selectedAnimation_;
	int x_, y_, direction_;
};