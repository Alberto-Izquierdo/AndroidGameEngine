#pragma once
namespace math
{
struct vec2f
{
	float x;
	float y;

	vec2f(float _value) : x(_value), y(_value) {};
	vec2f(float _x, float _y) : x(_x), y(_y) {};
	vec2f &operator+=(const vec2f &_other)
	{
		x += _other.x;
		y += _other.y;
		return *this;
	};
	vec2f &operator-=(const vec2f &_other)
	{
		x -= _other.x;
		y -= _other.y;
		return *this;
	};
	vec2f &operator*=(float _value)
	{
		x *= _value;
		y *= _value;
		return *this;
	}
	vec2f &operator/=(float _value)
	{
		x /= _value;
		y /= _value;
		return *this;
	}
};
struct mat4f
{
	float m_values[4][4];
	mat4f(float _value);
	mat4f(float *_values);

	static mat4f ortho(const vec2f &_resolution, const vec2f &_position);
};


} // namespace math

math::vec2f operator+(const math::vec2f &_a, const math::vec2f &_b);
math::vec2f operator-(const math::vec2f &_a, const math::vec2f &_b);
math::vec2f operator*(const math::vec2f &_a, float _value);
math::vec2f operator/(const math::vec2f &_a, float _value);
