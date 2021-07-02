#include "Sphere.h"

Sphere::Sphere()
{
	this->center = Vec3(0.0f, 0.0f, 0.0f);
	this->radius = 0.0f;
	this->color = Vec3(uint8_t(0), uint8_t(0), uint8_t(0));
}

Sphere::Sphere(Vec3 center, float radValue, Vec3 color)
{
	this->center = center;
	this->radius = radValue;
	this->color = color;
}

Sphere::~Sphere()
{
}

Vec3 Sphere::getColor()
{
	return this->color;
}

Vec3 Sphere::getCenter()
{
	return this->center;
}

float Sphere::getRadius()
{
	return this->radius;
}

bool Sphere::findIntersection(Ray ray, float& t)
{	
	Vec3 OC = ray.getOrigo() - this->center;
	float a = ray.getDirection().dotProduct(ray.getDirection()); // D^2
	float b = 2.0f * (ray.getDirection().dotProduct(OC)); // 2 * angle(OC, ray direction)
	float c = OC.dotProduct(OC) - (this->radius * this->radius);	
	
	float disc = (b * b) - (4 * a * c);
	if (disc < 0)	// miss
		return false;
	else {			// dubble hit or one hit at a corner
		float dist = (float)(sqrt((double)disc));
		float t0 = (-b - dist) / 2.0f * a;
		float t1 = (-b + dist) / 2.0f * a;

		if (t0 < t1) {
			t = t0;
		}
		else {
			t = t1;
		}
		return true;
	}
}
