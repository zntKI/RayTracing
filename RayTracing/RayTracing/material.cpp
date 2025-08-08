#include "material.hpp"

bool material::scatter (const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
{
	return false;
}

lambertian::lambertian (const color& albedo) : albedo(albedo)
{
}

bool lambertian::scatter (const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
{
	auto scatter_direction = rec.normal + random_unit_vector ();

	// Catch degenerate scatter direction
	if (scatter_direction.near_zero ())
		scatter_direction = rec.normal;

	scattered = ray (rec.p, scatter_direction);
	attenuation = albedo;

	return true;
}

metal::metal (const color& albedo, float fuzz) : albedo(albedo), fuzz(fuzz < 1 ? fuzz : 1)
{
}

bool metal::scatter (const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
{
	vec3 reflected = reflect (r_in.getDirection (), rec.normal);
	reflected = unit_vector (reflected) + (fuzz * random_unit_vector ());

	scattered = ray (rec.p, reflected);
	attenuation = albedo;

	return (dot(scattered.getDirection(), rec.normal) > 0);
}