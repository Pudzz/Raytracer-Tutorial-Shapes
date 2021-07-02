#pragma once
#include "Vec3.h"
#include "Ray.h"

class Sphere {
private:
	Vec3 center;
	float radius;
	Vec3 color;
public:
	Sphere();
	Sphere(Vec3 center, float radValue, Vec3 color);
	~Sphere();

	Vec3 getColor();
	Vec3 getCenter();
	float getRadius();

	bool findIntersection(Ray ray, float& t);
};