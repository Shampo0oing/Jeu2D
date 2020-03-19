#include "Character.h"


Character::Character(const std::string& path, int x, int y): selectedAnimation_("idle"), x_(x), y_(y)
{
	for (const auto& entry : std::filesystem::directory_iterator(path))
		animations_.insert({ entry.path().filename().u8string(), new Animation(entry.path().u8string()) });
}

void Character::render(sf::RenderWindow* rw)
{
	animations_[selectedAnimation_]->render(rw, x_, y_, direction_);
}

void Character::tick()
{
	animations_[selectedAnimation_]->tick();
}

void Character::selectAnimation(const std::string& name)
{
	if(animations_[selectedAnimation_]->isLooping() == false)
		animations_[selectedAnimation_]->reset();

	selectedAnimation_ = name;
}

void Character::move(int x, int y)
{
	if (x != 0)
		selectAnimation("run");

	if (x < 0)
		direction_ = 0;
	if (x > 0)
		direction_ = 1;

	x_ += x;
	y_ += y;

}
