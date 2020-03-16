#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

class Animation {

public:
	Animation(const std::string& path, const int& speed, const bool& loop);
	void render(sf::RenderWindow* rw);
	void tick();

private:
	std::vector<sf::Sprite*> sprites_;
	int speed_;
	int frame_;
	sf::Clock clock;
	int nbFiles_;
	bool loop_;

};
