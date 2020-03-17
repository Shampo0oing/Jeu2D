#include "Character.h"


Character::Character(const std::string& path): selectedAnimation_("idle")
{
	for (const auto& entry : std::filesystem::directory_iterator(path)) {

		animations_.insert({ entry.path().filename().u8string() , new Animation(entry.path().u8string()) });

	}
}

void Character::render(sf::RenderWindow* rw)
{
	animations_[selectedAnimation_]->render(rw);
}

void Character::tick()
{
	animations_[selectedAnimation_]->tick();
}

void Character::selectAnimation(const std::string& name)
{

	animations_[selectedAnimation_]->reset();
	selectedAnimation_ = name;
}
