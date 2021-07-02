#include "OBB.h"

Obb::Obb()
{
	this->center = Vec3(0.0f, 0.0f, 0.0f);

	this->dirX = Vec3(1.0f, 0.0f, 0.0f);
	this->dirY = Vec3(0.0f, 1.0f, 0.0f);
	this->dirZ = Vec3(0.0f, 0.0f, 1.0f);

	this->halfX = 0.0f;
	this->halfY = 0.0f;
	this->halfZ = 0.0f;

	this->color = Vec3(0.0f, 0.0f, 0.0f);
}

Obb::Obb(Vec3 center, Vec3 dirX, Vec3 dirY, Vec3 dirZ, float hX, float hY, float hZ, Vec3 color)
{
	this->center = center;
	this->dirX = dirX;
	this->dirY = dirY;
	this->dirZ = dirZ;

	this->halfX = hX;
	this->halfY = hY;
	this->halfZ = hZ;

	this->color = color;
}

Obb::~Obb()
{
}

Vec3 Obb::getColor()
{
	return this->color;
}

Vec3 Obb::getCenter()
{
	return this->center;
}

Vec3 Obb::getDirX()
{
	return this->dirX;
}

Vec3 Obb::getDirY()
{
	return this->dirY;
}

Vec3 Obb::getDirZ()
{
	return this->dirZ;
}

float Obb::getHalfX()
{
	return this->halfX;
}

float Obb::getHalfY()
{
	return this->halfY;
}

float Obb::getHalfZ()
{
	return this->halfZ;
}

bool Obb::findIntersection(Ray ray, float& t)
{
	float tMin = -INFINITY;
	float tMax = INFINITY;

	Vec3 pointVec = this->getCenter() - ray.getOrigo();
	Vec3 normalsArr[3] = { getDirX(), getDirY(), getDirZ() }; // normals
	float halflengthArr[3] = { getHalfX(), getHalfY(), getHalfZ() }; // half-lengths

	for (int x = 0; x < 3; x++) {

		float e = normalsArr[x].dotProduct(pointVec);
		float f = normalsArr[x].dotProduct(ray.getDirection());
		
		if (abs(f) > 0.0000001f) { // absolute-value

			float t1 = (e + halflengthArr[x]) / f;
			float t2 = (e - halflengthArr[x]) / f;
			if (t1 > t2) { std::swap(t1, t2); }
			if (t1 > tMin) { tMin = t1; }
			if (t2 < tMax) { tMax = t2; }
			if (tMin > tMax) { return false; }
			if (tMax < 0.0000001f) { return false; }
		}
		else if (-e - halflengthArr[x] > 0 || -e + halflengthArr[x] < 0) { return false; }
	}

	if (tMin > 0.0000001f) {
		t = tMin;
		return true;
	}
	else {
		t = tMax;
		return true;
	}
}
