#pragma once

#include "hittable.hpp"

#include "Utility/color.hpp"

class camera
{
public:

	float aspect_ratio = 1.0f; // Ratio of image width over height
	int image_width = 400; // Rendered image width in pixel count
	int samples_per_pixel = 10; // Count of random samples for each pixel

	void render (const hittable& world);

private:

	int image_height; // Rendered image height
	float pixel_samples_scale;
	point3 center; // Camera center
	point3 pixel00_loc; // Location of pixel 0, 0
	vec3 pixel_delta_u; // Offset to pixel to the right
	vec3 pixel_delta_v; // Offset to pixel below

	void initialize ();
	color ray_color (const ray& r, const hittable& world) const;

	ray get_ray (int i, int j) const;
	vec3 sample_square () const;
};