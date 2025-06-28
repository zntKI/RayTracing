#pragma once

#include "vec3.hpp"

class ray
{
public:

	ray ();
	ray (const point3& origin, const vec3& direction);

	const point3& getOrigin () const;
	const vec3& getDirection () const;

	point3 at (float t) const;

private:

	point3 origin;
	vec3 direction;
};