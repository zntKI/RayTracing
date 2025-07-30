#include "hittable.hpp"

void hit_record::set_face_normal (const ray& r, const vec3& outward_normal)
{
	// Sets the git record normal vector
	// NOTE: outward_normal is assumed to have unit length

	front_face = dot (r.getDirection (), outward_normal) < 0;
	normal = front_face ? outward_normal : -outward_normal;
}