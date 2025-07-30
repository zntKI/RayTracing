#include "sphere.hpp"

sphere::sphere (const point3& center, float radius)
	: center (center), radius (radius)
{
}

bool sphere::hit (const ray& r, interval ray_t, hit_record& rec) const
{
	vec3 oc = center - r.getOrigin ();

	vec3 rayDirection = r.getDirection ();

	auto a = rayDirection.length_sqaured ();
	auto h = dot (rayDirection, oc);
	auto c = oc.length_sqaured () - radius * radius;
	auto discriminant = h * h - a * c;

	if (discriminant < 0)
		return false;

	auto sqrtd = std::sqrt (discriminant);

	// Try with the nearest solution
	auto root = (h - sqrtd) / a;
	if (!ray_t.surrounds (root))
	{
		// If not, try with the solution that is further away
		root = (h + sqrtd) / a;
		if (!ray_t.surrounds (root))
			return false;
	}

	rec.t = root;
	rec.p = r.at (rec.t);
	vec3 outwawrd_normal = (rec.p - center) / radius;
	rec.set_face_normal (r, outwawrd_normal);

	return true;
}