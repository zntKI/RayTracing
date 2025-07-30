#pragma once

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

// Constants

const float infinity = std::numeric_limits<float>::infinity ();
const float pi = 3.1415926535897932385;

// Utility functions

inline float degrees_to_radians (float degrees)
{
	return degrees * pi / 180.0f;
}

inline float random_float () {
	// Returns a random real in [0, 1)
	return std::rand () / (RAND_MAX + 1.0);
}

inline float random_float (float min, float max) {
	// Returns a random real in [min, max)
	return min + (max - min) * random_float ();
}

// Common headers

#include "color.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include "interval.hpp"