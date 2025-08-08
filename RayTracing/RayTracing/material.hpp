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