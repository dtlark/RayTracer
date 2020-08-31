#pragma once
#include <vector>
#include "Ray.h"
//#include "Tuple.h"
#include "Point.h"
#include "Vector.h"
#include "Shape.h"
#include "Matrix.h"
//#include "Intersection.h"
#include "Material.h"
#include "Light.h"

using namespace std;

class Sphere : public Shape {

	double radius;

public:

	Sphere(double radius = 1, Material material = Material()) {
		
		type = "Sphere";

		ID = currID++;
		position = Point(0, 0, 0);
		this->radius = radius;
		this->material = material;
	}







void Print() {

	cout << "ID: " << ID << endl;
	cout << "Type: " << type << endl;
	cout << "Radius: " << radius << endl;

}


};


