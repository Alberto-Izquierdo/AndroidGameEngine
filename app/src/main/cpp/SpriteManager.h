#pragma once

#include <unordered_map>
#include <string>
#include <vector>

class SpriteManager
{
public:
	static SpriteManager &getInstance();

	std::vector<int> getImage(const std::string &_filepath);

protected:
	SpriteManager();
	~SpriteManager();
	std::vector<int> loadImage(const std::string &_filepath);
	std::unordered_map<std::string, std::vector<int>> m_imagesLoaded;
};
