#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <map>
#include <iterator>


class ImageLoader {

public:
	static sf::Sprite* LoadImage(const std::string& path);

private:
	static std::map<std::string, sf::Sprite*> images_;

};
