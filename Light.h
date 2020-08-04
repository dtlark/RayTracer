#pragma once
#include "Color.h"
#include "Point.h"

class Light {

	Color intensity;
	Point position;

public:

	Light() {
		intensity = Color(1, 1, 1);
		position = Point(0, 0, 0);
	}

	Light(Color intensity, Point position) {
		this->intensity = intensity;
		this->position = position;
	}



	void Print() {
	
		cout << "Light::: " << endl << "Intensity: ";
		intensity.Print();
		cout << "Position: " << endl;
		position.Print();
	}

	Color getIntensity() {
		return intensity;
	}
	void setPosition(Point position) {
		this->position = position;
	}
	Point getPosition() {
		return position;
	}

};

