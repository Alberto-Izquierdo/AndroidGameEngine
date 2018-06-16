#pragma once

#include <unordered_map>
#include <string>

class SpriteManager
{
public:
	static SpriteManager &getInstance();

	int getImage(const std::string &_filepath);

protected:
	SpriteManager();
	~SpriteManager();
	int loadImage(const std::string &_filepath);
	std::unordered_map<std::string, int> m_imagesLoaded;
};
