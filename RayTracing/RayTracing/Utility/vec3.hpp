#pragma once

#include <iostream>
#include <cmath>

class vec3
{
public:
	float e[3];

	vec3 ();
	vec3 (float e0, float e1, float e2);

	float x () const;
	float y () const;
	float z () const;
	
	vec3 operator-() const;
	float operator[](int i) const;
	float& operator[](int i);

	vec3& operator+=(const vec3& v);
	vec3& operator*=(float t);
	vec3& operator/=(float t);

	
	float length () const;

	float length_sqaured () const;
};

using point3 = vec3;

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