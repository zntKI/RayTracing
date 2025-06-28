#include "Utility/vec3.hpp"
#include "Utility/color.hpp"

#include <iostream>

int main () {

	// Image
	int image_width = 256;
	int image_height = 256;

	// Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {

		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

		for (int i = 0; i < image_width; i++) {

			auto pixel_color = color (i / float (image_width), j / float (image_height), 0);
			write_color (std::cout, pixel_color);

		}

	}

	std::clog << "\rDone.\n";
}