#include "Plane.h"

Plane::Plane()
{
	this->color = Vec3(uint8_t(0), uint8_t(0), uint8_t(0));
	this->distance = 0.0f;
	this->normal = Vec3(0.0f, 0.0f, 0.0f);
}

Plane::Plane(Vec3 normal, float distValue, Vec3 color)
{
	this->normal = normal;
	this->distance = distValue;
	this->color = color;
}

Plane::~Plane()
{
}

Vec3 Plane::getColor()
{
	return this->color;
}

Vec3 Plane::getNormal()
{
	return this->normal;
}

float Plane::getDistance()
{
	return this->distance;
}

bool Plane::findIntersection(Ray ray, float& t)
{
	// Plane
	float planeDist = this->getDistance();
	Vec3 planeNormal = this->getNormal();

	// Ray
	Vec3 rayori = ray.getOrigo();
	Vec3 raydir = ray.getDirection();

	float angle = raydir.dotProduct(this->normal); // check parallell
	if (angle == 0) {
		return false;
	}
	else {
		float dist = -planeDist - planeNormal.dotProduct(rayori);
		t = dist / angle;

		if (t > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	
}



