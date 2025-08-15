#pragma once

#include "hittable.hpp"

#include "Utility/color.hpp"

class camera
{
public:

	float aspect_ratio = 1.0f; // Ratio of image width over height
	int image_width = 400; // Rendered image width in pixel count
	int samples_per_pixel = 10; // Count of random samples for each pixel
	int max_depth = 10; // Max number of ray bounces into scene

	float vfov = 90.f;
	point3 lookfrom = point3 (0, 0, 0); // Point camera is looking from
	point3 lookat = point3 (0, 0, -1.f); // Point camera is looking at
	vec3 vup = vec3 (0, 1.f, 0); // Camera-relative "up" direction

	void render (const hittable& world);

private:

	int image_height; // Rendered image height
	float pixel_samples_scale;
	point3 center; // Camera center
	point3 pixel00_loc; // Location of pixel 0, 0
	vec3 pixel_delta_u; // Offset to pixel to the right
	vec3 pixel_delta_v; // Offset to pixel below
	vec3 u, v, w; // Camera frame basis vectors

	void initialize ();
	color ray_color (const ray& r, int depth, const hittable& world) const;

	ray get_ray (int i, int j) const;
	vec3 sample_square () const;
};