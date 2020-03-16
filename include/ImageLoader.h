#include <SFML/Graphics.hpp>
#include <filesystem>
#include <string>
#include <iostream>
#include <map>


class ImageLoader {

public:
	static sf::Sprite* LoadeImage(std::string& s);



private:
	sf::Sprite* sprite_;
	sf::Texture* texture_;
	int speed_;
	std::string ImagePath_;


};
