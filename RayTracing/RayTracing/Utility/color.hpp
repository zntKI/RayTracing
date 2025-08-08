#pragma once

#include "vec3.hpp"

#include <iostream>

using color = vec3;

void write_color (std::ostream& out, const color& pixel_color);

inline float linear_to_gamma (float linear_component)
{
	if (linear_component > 0)
		return std::sqrt (linear_component);

	return 0;
}