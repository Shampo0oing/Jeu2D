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
				cout << "Pas de fichier config pour " + entry.path().u8string() << endl;
			//lecture des attributs dans le config.txt
			else
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
	if (loop_ || frame_ < sprites_.size()-1) {
		if (clock.getElapsedTime().asMilliseconds() >= speed_) {
			if (frame_ < sprites_.size()) {
				frame_++;
				clock.restart();
			}

			if (!loop_ && frame_ == sprites_.size()-1) {
				// Quand l'animation se termine
			}
			else if (frame_ == sprites_.size())
				frame_ = 0;
		}
	}
}

void Animation::reset()
{
	frame_ = 0;
	clock.restart();
}

bool Animation::ended()
{
	return !loop_ && frame_ == sprites_.size() - 1;
}

bool Animation::isLooping()
{
	return loop_;
}

