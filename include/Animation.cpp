#include "Animation.h"
#include "ImageLoader.h"
#include <iostream>


Animation::Animation(const std::string& path, const int& speed, const bool& loop = false): speed_(speed), nbFiles_(0), frame_(0), loop_(loop)
{
	for (const auto& entry : std::filesystem::directory_iterator(path)) {

		sprites_.push_back(ImageLoader::LoadImage(entry.path().u8string()));
		nbFiles_++;
	}
}

void Animation::render(sf::RenderWindow* rw) {

	rw->draw(*sprites_[frame_]);
}

void Animation::tick() {
	if (clock.getElapsedTime().asMilliseconds() >= speed_) {
		
		
		if(loop_ || frame_ < nbFiles_ - 1)
			frame_++;

		if (frame_ ==  nbFiles_ && loop_)
			frame_ = 0;

		clock.restart();
	}
}
