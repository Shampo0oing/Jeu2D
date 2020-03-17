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
	Character(const std::string& path);
	void render(sf::RenderWindow* rw);
	void tick();
	void selectAnimation(const std::string& name);



private:
	std::map<std::string, Animation*> animations_;
	std::string selectedAnimation_;

};