/*
* Ray Tracer in C++
* 
* RayTracer.cpp : This file contains the 'main' function.
* Program execution begins and ends there.
* 
* by Deanna Lark (2020)
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <algorithm>

#include "Tuple.h"
#include "Color.h"
#include "Point.h"
#include "Vector.h"
#include "Canvas.h"
#include "Matrix.h"
#include "Ray.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Light.h"
#include "Material.h"
#include "Scene.h"
#include "Computations.h"

#define PI 3.141592653589

using namespace std;

double random_double() {
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937 generator;
	return distribution(generator);
}

int main() {

	//Sample Scene
	Scene scene = Scene();

	int resolution = 200;
	Canvas canvas = Canvas(resolution, resolution);
	canvas.Fill(Color(0, 0, 0));

	Light light = Light(Color(1, 1, 1), Point(-10, -10, -10));
	scene.addLight(light);

	Sphere circleSphere = Sphere();
	Material mat = circleSphere.getMaterial();
	mat.setColor(Color(1, 0.2, 0.6));
	circleSphere.setMaterial(mat);
	scene.addShape(circleSphere);

	Point camera = Point(0, 0, -5);
	Point wall = Point(0, 0, 10);
	double wallSize = 10;

	double pixelSize = wallSize / resolution;
	double half = wallSize / 2;

	for (int y = 0; y < resolution; y++) {
		double worldY = half - pixelSize * y;
		for (int x = 0; x < resolution; x++) {

			double worldX = -half + pixelSize * x;

			Point position = Point(worldX, worldY, wall.getZ());

			Point origin = Point(0, 0, -5);

			Vector direction = position - origin;
			direction = direction.normalize();

			Ray ray = Ray(origin, direction);

			vector<Intersection> inter = scene.intersectWorld(ray);

			Intersection hit = scene.Hit(inter);

			if (hit.getT() != -1) {
				Point hitPos = ray.position(hit.getT());
				Color color = circleSphere.lighting(hitPos, light, -ray.getDirection(), circleSphere.normalAt(hitPos));
				canvas.setPixel(x, y, color);
			}
		}
	}
	canvas.Save("SampleImage");
}
