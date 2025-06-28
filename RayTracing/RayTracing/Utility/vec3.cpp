#include "vec3.hpp"

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


inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3 (u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3 (u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3 (u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(float t, const vec3& v) {
	return vec3 (t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, float t) {
	return t * v;
}

inline vec3 operator/(const vec3& v, float t) {
	return (1 / t) * v;
}


inline double dot (const vec3& u, const vec3& v) {
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline vec3 cross (const vec3& u, const vec3& v) {
	return vec3 (u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector (const vec3& v) {
	return v / v.length ();
}