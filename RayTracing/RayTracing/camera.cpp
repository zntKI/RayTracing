#include "camera.hpp"

#include "Utility/utility.hpp"

void camera::render (const hittable& world)
{
	initialize ();

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {

		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

		for (int i = 0; i < image_width; i++) {

			auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
			auto ray_direction = pixel_center - center;

			ray r (center, ray_direction);
			color pixel_color = ray_color (r, world);

			write_color (std::cout, pixel_color);

		}
	}

	std::clog << "\rDone. \n";
}

void camera::initialize ()
{
	image_height = int (image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// Determine viewport dimensions.
	auto focal_length = 1.0f;
	auto viewport_height = 2.0f;
	auto viewport_width = viewport_height * (float (image_width) / image_height);

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	auto viewport_u = vec3 (viewport_width, 0, 0);
	auto viewport_v = vec3 (0, -viewport_height, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
	pixel_delta_u = viewport_u / image_width;
	pixel_delta_v = viewport_v / image_height;

	// Calculate the location of the upper left pixel.
	auto viewport_upper_left =
		center - vec3 (0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
	pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

color camera::ray_color (const ray& r, const hittable& world) const
{
	hit_record rec;
	if (world.hit (r, interval (0, infinity), rec))
	{
		return 0.5f * (rec.normal + color (1.f, 1.f, 1.f));
	}

	vec3 unit_direction = unit_vector (r.getDirection ());
	auto a = 0.5f * (unit_direction.y () + 1.0);
	return (1.0f - a) * color (1.f, 1.f, 1.f) + a * color (0.5f, 0.7f, 1.0f);
}
