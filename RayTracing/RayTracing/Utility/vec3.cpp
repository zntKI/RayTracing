#include "vec3.hpp"

#include "utility.hpp"

vec3::vec3 () : e{ 0, 0, 0 }
{
}

vec3::vec3 (float e0, float e1, float e2) : e{ e0, e1, e2 }
{
}


float vec3::x () const { return e[0]; }

float vec3::y () const { return e[1]; }

float vec3::z () const { return e[2]; }


vec3 vec3::operator-() const { return vec3 (-e[0], -e[1], -e[2]); }

float vec3::operator[](int i) const { return e[i]; }

float& vec3::operator[](int i) { return e[i]; }

vec3& vec3::operator+=(const vec3& v) {
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];

	return *this;
}

vec3& vec3::operator*=(float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;

	return *this;
}

vec3& vec3::operator/=(float t) {
	return *this *= 1 / t;
}

float vec3::length () const {
	return std::sqrt (length_sqaured ());
}

float vec3::length_sqaured () const {
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

vec3 vec3::random ()
{
	return vec3 (random_float (), random_float (), random_float ());
}

vec3 vec3::random (float min, float max)
{
	return vec3 (random_float (min, max), random_float (min, max), random_float (min, max));
}