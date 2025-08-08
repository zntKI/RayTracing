#include "color.hpp"

#include "interval.hpp"

void write_color (std::ostream& out, const color& pixel_color)
{
	auto r = pixel_color.x ();
	auto g = pixel_color.y ();
	auto b = pixel_color.z ();

	// Apply a linear to gamma transform for gamma 2
	r = linear_to_gamma (r);
	g = linear_to_gamma (g);
	b = linear_to_gamma (b);

	// Translate the [0,1] component values to the byte range [0,255]
	static const interval intensity (0.000f, 0.999f);
	int rbyte = int (256 * intensity.clapm(r));
	int gbyte = int (256 * intensity.clapm(g));
	int bbyte = int (256 * intensity.clapm(b));

	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}