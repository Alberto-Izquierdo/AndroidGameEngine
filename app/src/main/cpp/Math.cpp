#include "Math.h"

math::vec2f operator+(const math::vec2f &_a, const math::vec2f &_b)
{
	return math::vec2f(_a.x + _b.x, _a.y + _b.y);
}

math::vec2f operator-(const math::vec2f &_a, const math::vec2f &_b)
{
	return math::vec2f(_a.x - _b.x, _a.y - _b.y);
}

math::vec2f operator*(const math::vec2f &_a, float _value)
{
	return math::vec2f(_a.x * _value, _a.y * _value);
}

math::vec2f operator/(const math::vec2f &_a, float _value)
{
	return math::vec2f(_a.x / _value, _a.y / _value);
}
