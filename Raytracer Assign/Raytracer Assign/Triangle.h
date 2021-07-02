#pragma once
#include "Ray.h"
#include "Vec3.h"

class Triangle {
private:
	Vec3 A, B, C;
	Vec3 normal;
	float distance;
	Vec3 color;

public:
	Triangle();
	Triangle(Vec3 pointA, Vec3 pointB, Vec3 pointC, Vec3 color);
	~Triangle();

	Vec3 getNormal();
	float getDistance();
	Vec3 getColor();

	bool findIntersection(Ray ray, float& t);
};