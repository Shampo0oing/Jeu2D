#include "Character.h"


Character::Character(const std::string& path, int x, int y, float scale): selectedAnimation_("idle"), x_(x), y_(y), direction_(1)
{
	for (const auto& entry : std::filesystem::directory_iterator(path))
		animations_.insert({ entry.path().filename().u8string(), new Animation(entry.path().u8string(), scale) });
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
	if (selectedAnimation_ == "attack" && !animations_[selectedAnimation_]->ended())
		return;

	if(animations_[selectedAnimation_]->isLooping() == false)
		animations_[selectedAnimation_]->reset();

	selectedAnimation_ = name;
}

void Character::move(int x, int y)
{
	if (selectedAnimation_ == "attack")
		return;

	if (x != 0)
		selectAnimation("run");

	if (x < 0)
		direction_ = 0;
	else if (x > 0)
		direction_ = 1;

	x_ += x;
	y_ += y;

}