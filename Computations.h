#pragma once
#include "Shape.h"
#include "Point.h"
#include "Vector.h"
#include "Intersection.h"
#include "Ray.h"

class Computations {
	Shape shape;
	double t;
	Point point;
	Vector eye;
	Vector normal;
	bool inside;
public:

	Computations() {}

	Computations (Intersection i, Ray ray) { //PREPARE COMPUTATIONS
		this->shape = i.getObject();

		shape.getMaterial().Print();

		this->t = i.getT();

		this->point = ray.position(i.getT());
		this->eye = -ray.getDirection();
		this->normal = shape.normalAt(ray.position(i.getT()));
		
		if (normal.dot(eye) < 0) {
			inside = true;
			normal = -normal;
		}
		else {
			inside = false;
		}
	}

	void setShape(Shape shape) {
		this->shape = shape;
	}
	Shape getShape() {
		return shape;
	}
	void setT(double t) {
		this->t = t;
	}
	void setPoint(Point point) {
		this->point = point;
	}
	Point getPoint() {
		return point;
	}
	void setEye(Vector eye) {
		this->eye = eye;
	}
	Vector getEye() {
		return eye;
	}
	Vector setNormal(Vector normal) {
		this->normal = normal;
	}
	Vector getNormal() {
		return normal;
	}
	bool getInside() {
		return inside;
	}


	void Print() {
	
		cout << "Shape: " << endl;
		shape.Print();
		cout << "T: " << t << endl;
		cout << "Point: " << endl;
		point.Print();
		cout << "Eye: " << endl;
		eye.Print();
		cout << "Normal: " << endl;
		normal.Print();
		cout << "Inside?: " << endl;
		cout << inside<< endl;
	}

	
};

