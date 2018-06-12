#include "Sprite.h"

namespace Game {
Sprite::Sprite(const SpriteRegion &_spriteRegion)
	: m_position(0.f)
	, m_scale(0.f)
	, m_rotation(0.f)
	, m_spriteRegion(_spriteRegion)
{
}

Sprite::Sprite(int _image)
	: m_position(0.f)
	, m_scale(0.f)
	, m_rotation(0.f)
	, m_spriteRegion(_image)
{
}

Sprite::~Sprite()
{
}

void Sprite::update(float _delta)
{
}

void Sprite::render()
{
}

void Sprite::translate(const math::vec2f &_distance)
{
	m_position += _distance;
}

void Sprite::setPosition(const math::vec2f &_newPosition)
{
	m_position = _newPosition;
}

void Sprite::setRotation(float _rotation)
{
	m_rotation = _rotation;
}

void Sprite::rotate(float _angle)
{
	m_rotation += _angle;
	if (m_rotation > 360.f) {
		m_rotation -= 360.f;
	} else if (m_rotation < 0.f) {
		m_rotation += 360.f;
	}
}

} // namespace Game
