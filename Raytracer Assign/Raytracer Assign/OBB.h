#pragma once
#include "Vec3.h"
#include "Ray.h"
#include <math.h>

class Obb {
private:
	Vec3 center;
	Vec3 dirX, dirY, dirZ;
	float halfX, halfY, halfZ;
	Vec3 color;

public:
	Obb();
	Obb(Vec3 center, Vec3 dirX, Vec3 dirY, Vec3 dirZ, float hX, float hY, float hZ, Vec3 color);
	~Obb();

	Vec3 getColor();

	Vec3 getCenter();
	Vec3 getDirX();
	Vec3 getDirY();
	Vec3 getDirZ();

	float getHalfX();
	float getHalfY();
	float getHalfZ();

	bool findIntersection(Ray ray, float& t);
};