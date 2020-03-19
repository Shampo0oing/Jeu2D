#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <iomanip>
#include <algorithm>

class Animation {

public:
	Animation(const std::string& path, float scale);
	void render(sf::RenderWindow* rw, int x, int y, int direction);
	void tick();
	void reset();
	bool ended();
	bool isLooping();
	

private:
	std::vector<sf::Sprite*> sprites_;
	int speed_;
	int frame_;
	sf::Clock clock;
	bool loop_;
	float scale_;

};
