#include "Triangle.h"

Triangle::Triangle()
{
	this->A = Vec3(1.0f, 0.0f, 0.0f);
	this->B = Vec3(0.0f, 1.0f, 0.0f);
	this->C = Vec3(0.0f, 0.0f, 1.0f);
	this->normal = Vec3(1.0f, 0.0f, 0.0f);
	this->distance = 0.0f;
	this->color = Vec3(0.0f, 0.0f, 0.0f);
}

Triangle::Triangle(Vec3 pointA, Vec3 pointB, Vec3 pointC, Vec3 color)
{
	this->normal = getNormal();
	this->distance = getDistance();

	this->A = pointA;
	this->B = pointB;
	this->C = pointC;
	this->color = color;
}

Triangle::~Triangle()
{
}

Vec3 Triangle::getNormal()
{
	Vec3 AC = this->C - this->A;
	Vec3 AB = this->B - this->A;
	this->normal = AC.crossProduct(AB);
	Vec3 normal_normalized = this->normal.make_unitVector();

	return normal_normalized;
}

float Triangle::getDistance()
{
	this->normal = getNormal();
	this->distance = this->normal.dotProduct(this->A);

	return this->distance;
}

Vec3 Triangle::getColor()
{
	return this->color;
}

bool Triangle::findIntersection(Ray ray, float& t)
{	
	Vec3 rayOrigin = ray.getOrigo();

	this->normal = getNormal();
	this->distance = getDistance();

	float bValue = ray.getDirection().dotProduct(this->normal); // bottomvalue

	if (bValue == 0) {	return false; }
	else {
		float tValue = -this->distance - this->normal.dotProduct(rayOrigin); // topvalue
		float distance2plane = -1 - tValue / bValue; 

		// New vec3
		float Qx = (ray.getDirection() * distance2plane).getX() + rayOrigin.getX();
		float Qy = (ray.getDirection() * distance2plane).getY() + rayOrigin.getY();
		float Qz = (ray.getDirection() * distance2plane).getZ() + rayOrigin.getZ();
		Vec3 Q(Vec3(Qx, Qy, Qz));

		// ---Test distance to plane--- //

		// (CA x QA) * n >=0
		Vec3 AC = this->C - this->A;
		Vec3 AQ = Q - this->A;
		Vec3 ACAQ = AC.crossProduct(AQ);
		float t1 = ACAQ.dotProduct(normal);

		// (BC x QC) * n >=0
		Vec3 BC = this->B - this->C;
		Vec3 QC = Q - this->C;
		Vec3 BCQC = BC.crossProduct(QC);
		float t2 = BCQC.dotProduct(normal);

		// (AB x QB) * n >=0
		Vec3 AB = this->A - this->B;
		Vec3 QB = Q - this->B;
		Vec3 ABQB = AB.crossProduct(QB);
		float t3 = ABQB.dotProduct(normal);

		if ((t1 >= 0) && (t2 >= 0) && (t3 >= 0)) {

			// inside triangle
			t = distance2plane;
			return true;
		}
		else {

			// outside triangle
			return false;
		}
	}
}
