#pragma once

#include <map>
#include <string>

class SpriteManager
{
public:
	static SpriteManager &getInstance();

	int getImage(const std::string &_filepath);

protected:
	SpriteManager();
	~SpriteManager();
	std::map<std::string, int> m_imagesLoaded;
};
