#pragma once

#include "hittable.hpp"
#include "Utility/color.hpp"

class material
{
public:

	virtual ~material () = default;

	virtual bool scatter (const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered);
};

class lambertian : public material
{
public:

	lambertian (const color& albedo);

	bool scatter (const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) override;

private:

	color albedo;
};

class metal : public material
{
public:

	metal (const color& albedo, float fuzz);

	bool scatter (const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) override;

private:

	color albedo;
	float fuzz;
};

class dielectric : public material {
public:

	dielectric (float refraction_index);

	bool scatter (const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) override;

private:

	// Refractive index in vacuum or air, or the ratio of the material's refractive index over
	// the refractive index of the enclosing media
	float refraction_index;

	static float reflectance (float cosine, float refraction_index) {
		// Use Schlick's approximation for reflectance.
		auto r0 = (1.0f - refraction_index) / (1.0 + refraction_index);
		r0 = r0 * r0;
		return r0 + (1 - r0) * std::pow ((1 - cosine), 5);
	}
};