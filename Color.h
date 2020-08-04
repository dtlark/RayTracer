#pragma once
#include "Tuple.h"

class Color : public Tuple {
public:
	Color(double r = 0, double g = 0, double b = 0, double o = 1) {
		x = r;
		y = g;
		z = b;
		w = o;
		type = 2;
	}
	//Effect - Add: 2 Colors
	Color Add(Color color) {
		return Color(x + color.x,
					 y + color.y,
					 z + color.z);
	}
	//Effect - Subtract: 2 Colors
	Color Subtract(Color color) {
		return Color(x - color.x,
					 y - color.y,
					 z - color.z);
	}
	//Effect - Multiply: 2 Colors (Hadamard Product)
	Color Multiply (Color color) {
		return Color(x * color.x,
					 y * color.y,
					 z * color.z);	
	}
	//Effect - Multiply: Scalar Multiplication
	Color Multiply(double val) {
		return Color(x * val,
					 y * val,
					 z * val);
	}

	double getR() {
		return x;
	}
	double getG() {
		return y;
	}
	double getB() {
		return z;
	}
	int getO() {
		return w;
	}
	void Normalize() {

	};

	Color operator*(double const& other) {
		double _x = this->x * other;
		double _y = this->y * other;
		double _z = this->z * other;
		return Color(_x, _y, _z);
	}

	Color operator+(Color const& other) {
		double _x = this->x + other.getX();
		double _y = this->y + other.getY();
		double _z = this->z + other.getZ();
		return Color(_x, _y, _z);
	}

	Color operator*(Color const& other) {
		double _x = this->x * other.getX();
		double _y = this->y * other.getY();
		double _z = this->z * other.getZ();
		return Color(_x, _y, _z);
	}
};

