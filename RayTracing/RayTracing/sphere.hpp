#pragma once

#include "hittable.hpp"

#include "Utility/vec3.hpp"
#include "Utility/interval.hpp"

class sphere : public hittable
{
public:

	sphere (const point3& center, float radius, std::shared_ptr<material> mat);

	bool hit (const ray& r, interval ray_t, hit_record& rec) const override;
	 
private:

	point3 center;
	float radius;
	std::shared_ptr<material> mat;
};