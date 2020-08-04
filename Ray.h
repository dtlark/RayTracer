#pragma once
#include "Tuple.h"
#include "Point.h"
#include "Matrix.h"
#include "Vector.h"

class Ray {

	Point origin;
	Vector direction;

public:

	Ray(Point origin, Vector direction) {
		this->origin = origin;
		this->direction = direction;
	}

	Ray() {
		origin = Point();
		direction = Vector();
	}
	

	Point at(double t) {
	
		//return origin + t * direction;
	}



	Ray transform(Matrix mat) {
		Ray temp = Ray(origin, direction);
		return temp * mat;
	}


	Ray operator*(Matrix matrix) {
	
		Ray temp = Ray();
		temp.origin = matrix * origin;
		temp.direction = matrix * direction;

		return temp;

	}
	

	Point position(double t) {
		return origin + direction * t;
	}
	
	double discriminant() {
	
	
	
	


	}

	Point getOrigin() {
		return origin;
	}

	Vector getDirection() {
		return direction;
	}

	void Print() {
		cout << "Ray: " << endl;
		cout << "Origin: " << endl;
		origin.Print();
		cout << " Direction: " << endl;
		direction.Print();

	
	}

};

