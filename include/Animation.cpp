#include "Animation.h"
#include "ImageLoader.h"
#include <iostream>
#include <fstream>
using namespace std;


Animation::Animation(const string& path): frame_(0), loop_(false), speed_(200)
{
	for (const auto& entry : filesystem::directory_iterator(path)) {
		//ajoute chaque sprite pour donner une animation
		if (entry.path().extension().u8string() == ".png")
			sprites_.push_back(ImageLoader::LoadImage(entry.path().u8string()));

		else {

			//ouvre le config.txt
			ifstream fichierConfig(entry.path());
			if (!fichierConfig.is_open())
				break;
			//lecture des attributs dans le config.txt
			fichierConfig >> speed_ >> loop_;
			//ferme config.txt
			fichierConfig.close();
			
			
		}
	}
}

void Animation::render(sf::RenderWindow* rw) {

	rw->draw(*sprites_[frame_]);
}

void Animation::tick() {
	if (clock.getElapsedTime().asMilliseconds() >= speed_) {
		
		if (frame_ < sprites_.size())
			frame_ ++;

		if (frame_ == sprites_.size())
			frame_ = 0;

		clock.restart();
	}
}

void Animation::reset()
{
	frame_ = 0;
	clock.restart();
}

