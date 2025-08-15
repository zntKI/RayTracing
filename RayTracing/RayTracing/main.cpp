#include "Utility/utility.hpp"

#include "Utility/vec3.hpp"
#include "Utility/color.hpp"
#include "Utility/ray.hpp"

#include "hittable.hpp"
#include "hittable_list.hpp"
#include "material.hpp"
#include "sphere.hpp"

#include "camera.hpp"

#include <iostream>

int main () {

	hittable_list world;

	auto material_ground = std::make_shared<lambertian> (color (0.8f, 0.8f, 0.f));
	auto material_center = std::make_shared<lambertian> (color (0.1f, 0.2f, 0.5f));
	auto material_left = std::make_shared<dielectric> (1.50f);
	auto material_bubble = std::make_shared<dielectric> (1.00f / 1.50f);
	auto material_right = std::make_shared<metal> (color (0.8f, 0.6f, 0.2f), 0.3f);

	world.add (std::make_shared<sphere> (point3 (0, -100.5, -1), 100, material_ground));
	world.add (std::make_shared<sphere> (point3 (0, 0, -1.2f), 0.5, material_center));
	world.add (std::make_shared<sphere> (point3 (-1.f, 0, -1), 0.5, material_left));
	world.add (std::make_shared<sphere> (point3 (-1.f, 0, -1), 0.4, material_bubble));
	world.add (std::make_shared<sphere> (point3 (1.f, 0, -1), 0.5, material_right));

	camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;
	cam.samples_per_pixel = 100;
	cam.max_depth = 50;

	cam.render (world);

}