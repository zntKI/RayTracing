#include "ray.hpp"

ray::ray ()
{
}

ray::ray (const point3& origin, const vec3& direction)
	: origin(origin), direction(direction)
{
}

const point3& ray::getOrigin () const
{
	return origin;
}

const vec3& ray::getDirection () const
{
	return direction;
}

point3 ray::at (float t) const
{
	return origin + direction * t;
}