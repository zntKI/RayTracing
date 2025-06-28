#include "Utility/vec3.hpp"
#include "Utility/color.hpp"
#include "Utility/ray.hpp"

#include <iostream>

float hit_sphere (const point3& sphereCenter, float radius, const ray& r)
{
	vec3 oc = sphereCenter - r.getOrigin ();

	vec3 rayDirection = r.getDirection ();

	auto a = rayDirection.length_sqaured();
	auto h = dot (rayDirection, oc);
	auto c = oc.length_sqaured() - radius * radius;
	auto discriminant = h * h - a * c;

	if (discriminant < 0) {
		return -1.0f;
	}
	else {
		return (h - std::sqrt (discriminant)) / a;
	}
}

color ray_color (const ray& r) {
	float sphere_radius = 0.5f;
	auto t = hit_sphere (point3 (0.f, 0.f, -1.f), sphere_radius, r);
	if (t > 0.0f) {
		vec3 N = (r.at (t) - vec3 (0.f, 0.f, -1.f)) / sphere_radius;
		return 0.5 * color (N.x () + 1, N.y () + 1, N.z () + 1);
	}

	vec3 unit_direction = unit_vector (r.getDirection ());
	auto a = 0.5f * (unit_direction.y () + 1.0);
	return (1.0f - a) * color (1.f, 1.f, 1.f) + a * color (0.5f, 0.7f, 1.0f)/*light blue*/;
}

int main () {

	// Image

	auto aspect_ratio = 16.0f / 9.0;
	int image_width = 400;

	// Calculate the image height, and ensure that it's at least 1.
	int image_height = int (image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// Camera

	auto focal_length = 1.0f;
	auto viewport_height = 2.0f;
	auto viewport_width = viewport_height * (float (image_width) / image_height);
	auto camera_center = point3 (0, 0, 0);

	// Calculate the vectors across the horizontal and down the vertical viewport edges
	auto viewport_u = vec3 (viewport_width, 0, 0);
	auto viewport_v = vec3 (0, -viewport_height, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	// Calculate the location of the upper left pixel
	auto viewport_upper_left = camera_center - vec3 (0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
	auto pixel100_loc = viewport_upper_left + 0.5f * (pixel_delta_u + pixel_delta_v);

	// Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {

		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

		for (int i = 0; i < image_width; i++) {

			auto pixel_center = pixel100_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
			auto ray_direction = pixel_center - camera_center;
			ray r (camera_center, ray_direction);

			color pixel_color = ray_color (r);
			write_color (std::cout, pixel_color);

		}

	}

	std::clog << "\rDone.\n";
}