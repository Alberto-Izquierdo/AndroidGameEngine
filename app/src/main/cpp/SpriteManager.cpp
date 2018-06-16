#include "SpriteManager.h"
#include "Game.h"

SpriteManager &SpriteManager::getInstance()
{
	static SpriteManager spriteManager;
	return spriteManager;
}

int SpriteManager::getImage(const std::string &_filepath)
{
    std::unordered_map<std::string, int>::iterator it = m_imagesLoaded.find(_filepath);
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

int SpriteManager::loadImage(const std::string &_filepath)
{
	int image = Game::Game::loadImage(_filepath.c_str());
	m_imagesLoaded[_filepath] = image;
	return image;

}
