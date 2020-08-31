#pragma once
#include <iostream>
#include "Shape.h"
#include "Ray.h"
using namespace std;

class Intersection {

	Shape object; //Object
	double t;

public: 

	Intersection() {
		this->t = -1;
	}

	Intersection(Shape object, double t) {
	
		this->object = object;
		this->t = t;
	}


	double getT() {
		return t;
	}
	Shape getObject() {
		return object;
	}

	bool operator==(Intersection other) {
	
		//if (object == other.object && t == other.getT()) {
		//	return true;
		//}
		//return false;


	}

	bool operator!=(Intersection other) {

		if (t == other.t) {
			return false;
		}
		return true;


	}

	void Print() {
		cout << "Intersection: " << object.getID() << endl;
		cout << "T: " << t << endl;
	}

};

