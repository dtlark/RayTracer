#pragma once
#include "Color.h"

class Material {

	Color color;
	double ambient;
	double diffuse;
	double specular;
	double shine;

public:

	Material(Color color = Color(1, 1, 1), double ambient = 0.1, double diffuse = 0.9, double specular = 0.9, double shine = 200.0) {
		this->color = color;
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
		this->shine = shine;
	}

	double getAmbient() {
		return ambient;
	}
	void setAmbient(double ambient) {
		if (ambient < 0) {
			ambient = 0;
		}
		this->ambient = ambient;
	}

	double getDiffuse() {
		return diffuse;
	}
	void setDiffuse(double diffuse) {
		if (diffuse < 0) {
			diffuse = 0;
		}
		this->diffuse = diffuse;
	}

	double getSpecular() {
		return specular;
	}
	void setSpecular(double specular) {
		if (specular < 0) {
			specular = 0;
		}
		this->specular = specular;
	}

	double getShine() {
		return shine;
	}
	void setShine(double shine) {
		if (shine < 10) {
			shine = 10;
		}
		if (shine > 200) {
			shine = 200;
		}

		this->shine = shine;
	}

	void setColor(Color color) {
		this->color = color;
	}

	Color getColor() {
		return color;
	}
	
	void Print() {
		cout << "Color: " << endl;
		color.Print();
		cout << "Ambient: " << endl;
		cout << ambient << endl;
		cout << "Diffuse: " << endl;
		cout << diffuse << endl;
		cout << "Specular: " << endl;
		cout << specular << endl;
		cout << "Shine: " << endl;
		cout << shine << endl;
	}
};

