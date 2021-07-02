#pragma once
#include "Vec3.h"
#include "Ray.h"

class Plane {
private:
	Vec3 normal;
	float distance;
	Vec3 color;

public:
	Plane();
	Plane(Vec3 normal, float distValue, Vec3 color);
	~Plane();

	Vec3 getColor();
	Vec3 getNormal();
	float getDistance();

	bool findIntersection(Ray ray, float& t);
};