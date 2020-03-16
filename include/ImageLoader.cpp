#include "ImageLoader.h"
#include <filesystem>
using namespace std;
using namespace sf;

std::map<std::string, sf::Sprite*> ImageLoader::images_;

Sprite* ImageLoader::LoadImage(const string& path) 
{
	if (images_.find(path) == images_.end()) {

		Texture* texture = new Texture;
		texture->loadFromFile(path);
		Sprite* sprite = new Sprite(*texture);
		sprite->scale(3.0, 3.0);
		images_[path] = sprite;
	}

	return images_[path];
}

