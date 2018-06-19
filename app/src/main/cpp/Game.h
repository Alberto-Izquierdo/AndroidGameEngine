#pragma once

#include <vector>
#include <memory>

namespace Game
{
class Sprite;
class Game
{
public:
	Game();
	~Game();

	void init();

	void update(float _delta);
	void render();

	static int* loadImage(const char* _filepath);
protected:
	std::vector<std::unique_ptr<Sprite>> m_sprites;
};
} // namespace Game
