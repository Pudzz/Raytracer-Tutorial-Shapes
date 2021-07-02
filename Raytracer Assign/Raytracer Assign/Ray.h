#pragma once
#include "Vec3.h"

class Ray {
private:
	Vec3 origo;
	Vec3 direction;
public:
	Ray();
	Ray(Vec3 ori, Vec3 dir);
	~Ray();

	Vec3 getOrigo();
	Vec3 getDirection();
};