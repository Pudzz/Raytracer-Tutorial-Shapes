#include <iostream>
#include <stdint.h>
#include "Vec3.h"
#include "Ray.h"
#include "Plane.h"
#include "Sphere.h"
#include "OBB.h"
#include "Triangle.h"

using namespace std;

// RGB Color
struct Color {
	uint8_t r, g, b;
	Color() { r = 0; g = 0; b = 0; }
	Color(uint8_t red, uint8_t green, uint8_t blue) { r = red; g = green; b = blue; }
};

void setpixel(uint8_t* image, int width, int channels, int x, int y, uint8_t r, uint8_t g, uint8_t b);
void write_ppm(const char* filename, const uint8_t* image, int width, int height, int channels);

int main() {
	cout << "Rendering.." << endl;

	int width = 256;
	int height = 256;
	int channels = 3;

	Vec3 color((uint8_t)0, (uint8_t)0, (uint8_t)0);

	// --- Colors --- //
	Vec3 red(uint8_t(255), uint8_t(0), uint8_t(0));
	Vec3 green(uint8_t(0), uint8_t(255), uint8_t(0));
	Vec3 blue(uint8_t(0), uint8_t(0), uint8_t(255));
	Vec3 orange((uint8_t)255, (uint8_t)108, (uint8_t)0);

	// unitvectors
	Vec3 unitX(1.0f, 0.0f, 0.0f);
	Vec3 unitY(0.0f, 1.0f, 0.0f);
	Vec3 unitZ(0.0f, 0.0f, 1.0f);

	// --- Objects --- //
	Plane plane(Vec3(0.0f, 0.0f, -1.0f), 200.0f, red);
	Sphere sphere(Vec3((float)width / 2.0f, (float)height / 2.0f, 100.0f), 60.0f, green);
	Obb obb(Vec3((float)width / 4.0f, (float)height / 4.0f, 140.0f), unitX, unitY, unitZ, (float)width / 4.0f, (float)height / 4.0f, 20.0f, blue);
	Triangle triangle(Vec3((float)width / 2, 40.0f, 180.0f), Vec3((float)width / 2, (float)height / 2, 180.0f), Vec3((float)width, 0.0f, 180.0f), orange);

	// alloc memory
	uint8_t* image_data = (uint8_t*)calloc(width * height * channels * sizeof(uint8_t), 1);
		
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			Ray ray(Vec3((float)x, (float)y, 0.0f), Vec3(0.0f, 0.0f, 1.0f));
			
			float t = 0.0f;
			float closest = 1000.0f;

			if (plane.findIntersection(ray, t)) {
				if (t < closest) {
					closest = t;
					color.setR(plane.getColor().getR());
					color.setG(plane.getColor().getG());
					color.setB(plane.getColor().getB());
				}
			}
			if (sphere.findIntersection(ray, t)) {
				if (t < closest) {
					closest = t;
					color.setR(sphere.getColor().getR());
					color.setG(sphere.getColor().getG());
					color.setB(sphere.getColor().getB());
				}
			}
			if (obb.findIntersection(ray, t)) {
				if (t < closest) {
					closest = t;
					color.setR(obb.getColor().getR());
					color.setG(obb.getColor().getG());
					color.setB(obb.getColor().getB());
				}
			}
			if (triangle.findIntersection(ray, t))
			{
				if (t < closest) {
					closest = t;
					color.setR(triangle.getColor().getR());
					color.setG(triangle.getColor().getG());
					color.setB(triangle.getColor().getB());
				}
			}
						
			setpixel(image_data, width, channels, x, y, color.getR(), color.getG(), color.getB());			
		}
	}

	cout << "Render done!" << endl;
	write_ppm("picture.ppm", image_data, width, height, channels);
	return 0;
}

void setpixel(uint8_t* image, int width, int channels, int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
	int p_index = (width * y + x) * channels;
	image[p_index + 0] = r;
	image[p_index + 1] = g;
	image[p_index + 2] = b;
}

void write_ppm(const char* filename, const uint8_t* image, int width, int height, int channels)
{
	FILE* file_ptr = fopen(filename, "wb");
	fprintf(file_ptr, "P6\n%i %i\n255\n", width, height);
	fwrite(image, width * height * channels, 1, file_ptr);
	fclose(file_ptr);
}
