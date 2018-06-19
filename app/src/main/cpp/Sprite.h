#pragma once

#include "Math.h"
#include <string>
#include <vector>

namespace Game
{
struct SpriteRegion
{
	std::vector<int> m_image; // 3 values: id, width, height
	math::vec2f m_uvCoordinates; // values in [0,1]
	math::vec2f m_uvSizes; // values in [0,1]

	SpriteRegion(const std::vector<int> &_image)
		: m_image(_image)
        , m_uvCoordinates(0, 0)
		, m_uvSizes(1, 1) {};

	SpriteRegion(const std::vector<int> &_image,
				 const math::vec2f &_uvCoordinates,
				 const math::vec2f &_uvSizes)
		: m_image(_image)
        , m_uvCoordinates(_uvCoordinates)
		, m_uvSizes(_uvSizes) {};
};

class Sprite
{
public:
	Sprite(const SpriteRegion &_spriteRegion);
	Sprite(const std::vector<int> &_image);
	Sprite(const std::string &_image);
	~Sprite();

	void update(float _delta);
	void render();

	void translate(const math::vec2f &_distance);
	void setPosition(const math::vec2f &_newPosition);
	void setRotation(float _rotation);
	void rotate(float _angle);

protected:
	math::vec2f m_position;
	math::vec2f m_scale;
	float m_rotation;
	SpriteRegion m_spriteRegion;
};
} // namespace Game
