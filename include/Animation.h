#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <iomanip>
#include <algorithm>

class Animation {

public:
	Animation(const std::string& path);
	void render(sf::RenderWindow* rw);
	void tick();
	void reset();
	

private:
	std::vector<sf::Sprite*> sprites_;
	int speed_;
	int frame_;
	sf::Clock clock;
	bool loop_;

};
