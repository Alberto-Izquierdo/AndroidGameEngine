#include "Math.h"

namespace math
{
vec2f operator+(const vec2f &_a, const vec2f &_b)
{
	return vec2f(_a.x + _b.x, _a.y + _b.y);
}

vec2f operator-(const vec2f &_a, const vec2f &_b)
{
	return vec2f(_a.x - _b.x, _a.y - _b.y);
}

vec2f operator*(const vec2f &_a, float _value)
{
	return vec2f(_a.x * _value, _a.y * _value);
}

vec2f operator/(const vec2f &_a, float _value)
{
	return vec2f(_a.x / _value, _a.y / _value);
}

mat4f::mat4f(float _value)
{
	for (int i = 0; i < 4; ++i) {
		m_values[i][0] = m_values[i][1] = m_values[i][2] = m_values[i][3] = _value;
	}
}

mat4f::mat4f(float *_values)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_values[i][j] = _values[j + i * 4];
		}
	}
}

mat4f mat4f::ortho(const vec2f &_resolution, const vec2f &_position)
{
	float matrix [16];
	matrix[0] = 2.f / (_resolution.x + _position.x);
	matrix[1] = 0.f;
	matrix[2] = 0.f;
	matrix[3] = 0.f;
	matrix[4] = 0.f;
	matrix[5] = 2.f / (_resolution.y + _position.y);
	matrix[6] = 0.f;
	matrix[7] = 0.f;
	matrix[8] = 0.f;
	matrix[9] = 0.f;
	matrix[10] = 1 / (10.f - 0.1f);
	matrix[11] = 0.f;
	matrix[12] = 0.f;
	matrix[13] = 0.f;
	matrix[14] = -0.1f / (10.f - 0.1f);
	matrix[15] = 0.f;
	return mat4f(matrix);
}
};
