namespace math
{
struct vec2f
{
	float x;
	float y;
	vec2f(float _value) : x(_value), y(_value) {};
	vec2f(float _x, float _y) : x(_x), y(_y) {};
};
struct vec3f
{
	float x;
	float y;
	float z;
	vec3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
	vec3f(vec2f &_vec2, float _z) : x(_vec2.x), y(_vec2.y), z(_z) {};
};
struct math3
{
};
} // namespace math
