#include "material.hpp"

#include "Utility/utility.hpp"

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

dielectric::dielectric (float refraction_index) : refraction_index(refraction_index)
{
}

bool dielectric::scatter (const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
{
	attenuation = color (1.0f, 1.0f, 1.0f);
	float ri = rec.front_face ? (1.0 / refraction_index) : refraction_index;

	vec3 unit_direction = unit_vector (r_in.getDirection ());
	float cos_theta = std::fminf (dot (-unit_direction, rec.normal), 1.0);
	float sin_theta = std::sqrt (1.0f - cos_theta * cos_theta);

	bool cannot_refract = ri * sin_theta > 1.0;

	vec3 direction;
	if (cannot_refract || reflectance(cos_theta, ri) > random_float())
		direction = reflect (unit_direction, rec.normal);
	else
		direction = refract (unit_direction, rec.normal, ri);

	scattered = ray (rec.p, direction);
	return true;
}