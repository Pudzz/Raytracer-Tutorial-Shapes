#include "Ray.h"

Ray::Ray()
{
	this->origo = Vec3(0.0f, 0.0f, 0.0f);
	this->direction = Vec3(0.0f, 0.0f, 1.0f); 
}

Ray::Ray(Vec3 ori, Vec3 dir)
{
	this->origo = ori;
	this->direction = dir;
}

Ray::~Ray()
{
}

Vec3 Ray::getOrigo()
{
	return this->origo;
}

Vec3 Ray::getDirection()
{
	return this->direction;
}
