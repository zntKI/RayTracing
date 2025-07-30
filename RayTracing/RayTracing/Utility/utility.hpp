#pragma once

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// Constants

const float infinity = std::numeric_limits<float>::infinity ();
const float pi = 3.1415926535897932385;

// Utility functions

inline double degrees_to_radians (float degrees)
{
	return degrees * pi / 180.0f;
}

// Common headers

#include "color.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include "interval.hpp"