#include "SpriteManager.h"
#include "Game.h"

SpriteManager &SpriteManager::getInstance()
{
	static SpriteManager spriteManager;
	return spriteManager;
}

std::vector<int> SpriteManager::getImage(const std::string &_filepath)
{
    auto it = m_imagesLoaded.find(_filepath);
	if (it != m_imagesLoaded.end()) {
		return it->second;
	}

	return loadImage(_filepath);
}

SpriteManager::SpriteManager()
{
}

SpriteManager::~SpriteManager()
{
}

std::vector<int> SpriteManager::loadImage(const std::string &_filepath)
{
	int *image = Game::Game::loadImage(_filepath.c_str());
	m_imagesLoaded[_filepath] = {image[0], image[1], image[2]};
	return m_imagesLoaded[_filepath];

}
