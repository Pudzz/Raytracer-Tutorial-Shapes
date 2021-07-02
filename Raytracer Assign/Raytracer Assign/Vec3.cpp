#include "Vec3.h"

Vec3::Vec3()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->r = (uint8_t)0;
	this->g = (uint8_t)0;
	this->b = (uint8_t)0;
}

Vec3::Vec3(float xCoord, float yCoord, float zCoord)
{	
	this->x = xCoord; 
	this->y = yCoord; 
	this->z = zCoord;

	this->r = (uint8_t)0;
	this->g = (uint8_t)0;
	this->b = (uint8_t)0;
}

Vec3::Vec3(uint8_t red, uint8_t green, uint8_t blue)
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;

	this->r = red;
	this->g = green;
	this->b = blue;
}

Vec3::~Vec3()
{
}

float Vec3::getX()
{
	return this->x;
}

float Vec3::getY()
{
	return this->y;
}

float Vec3::getZ()
{
	return this->z;
}

uint8_t Vec3::getR()
{
	return this->r;
}

uint8_t Vec3::getG()
{
	return this->g;
}

uint8_t Vec3::getB()
{
	return this->b;
}

void Vec3::setR(uint8_t red)
{
	this->r = red;
}

void Vec3::setG(uint8_t green)
{
	this->g =green;
}

void Vec3::setB(uint8_t blue)
{
	this->b = blue;
}

float Vec3::halfLength()
{
	return length() / 2.0f;
}

float Vec3::length()
{	
	return (float)sqrt((double)this->getX() * (double)this->getX() + (double)this->getY() * (double)this->getY() + (double)this->getZ() * (double)this->getZ());
}

float Vec3::squarelength()
{
	return (float)((double)this->getX() * (double)this->getX() + (double)this->getY() * (double)this->getY() + (double)this->getZ() * (double)this->getZ());
}

float Vec3::dotProduct(Vec3 v)
{
	return ((this->getX() * v.getX()) + (this->getY() * v.getY()) + (this->getZ()* v.getZ()));
}

Vec3 Vec3::crossProduct(Vec3 v)
{
	return Vec3((this->getY() * v.getZ()) - (v.getY() * this->getZ()),
				(v.getX() * this->getZ()) - (this->getX() * v.getZ()),
				(this->getX() * v.getY()) - (v.getX() * this->getY()));
}

Vec3 Vec3::make_unitVector()
{
	float unit = 1.0f / length();

	return Vec3(this->getX() * unit, this->getY() * unit, this->getZ() * unit);
}

Vec3 Vec3::negativeVec3()
{
	return Vec3(-this->getX(), -this->getY(), -this->getZ());
}

Vec3 Vec3::operator*(float t)
{
	return Vec3(this->getX() * t, this->getY() * t, this->getZ() * t);
}

Vec3 Vec3::operator/(float t)
{
	return Vec3(this->getX() / t, this->getY() / t, this->getZ() / t);
}

Vec3 Vec3::operator+(const Vec3& v) const
{
	return Vec3(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const
{
	return Vec3(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vec3 Vec3::operator*(const Vec3& v) const
{
	return Vec3(this->x * v.x, this->y * v.y, this->z * v.z);
}

Vec3 Vec3::operator/(const Vec3& v) const
{
	return Vec3(this->x / v.x, this->y / v.y, this->z / v.z);
}
