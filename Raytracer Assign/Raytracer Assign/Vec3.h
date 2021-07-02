#pragma once
#include <stdint.h>
#include <math.h>
#include <string>

class Vec3 {
private:
	float x, y, z;
	uint8_t r, g, b;

public:
	Vec3();
	Vec3(float xCoord, float yCoord, float zCoord);
	Vec3(uint8_t red, uint8_t green, uint8_t blue);
	~Vec3();

	float getX();
	float getY();
	float getZ();

	uint8_t getR();
	uint8_t getG();
	uint8_t getB();
	void setR(uint8_t red);
	void setG(uint8_t green);
	void setB(uint8_t blue);

	// halflength to OBB
	float halfLength();

	float length();
	float squarelength(); // Vec3 ^2
	float dotProduct(Vec3 v);
	Vec3 crossProduct(Vec3 v);
	Vec3 make_unitVector();
	Vec3 negativeVec3();

	//Scalar multi/divi
	Vec3 operator*(float t);
	Vec3 operator/(float t);

	// Operators
	Vec3 operator+(const Vec3& v) const;
	Vec3 operator-(const Vec3& v) const;
	Vec3 operator*(const Vec3& v) const;
	Vec3 operator/(const Vec3& v) const;
};