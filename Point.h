#pragma once
#include "Tuple.h"
#include "Vector.h"

class Point : public Tuple {

public:
	Point(double r = 0, double g = 0, double b = 0) {
		x = r;
		y = g;
		z = b;
		w = 1;
		type = 1;
	}

	void operator=(Point const& other);
	bool operator==(Point const& other) const;
	Point operator+(Point const& other) const; //TODO: Remove
	Point operator+(Vector const& other) const;
	Vector operator-(Point other);
	Point minus(Point me, Point other); //TODO: Fix this
	Point operator-() const;
	Point operator*(double num) const;
	Point operator*(Point const& other) const;
	Point operator/(double num) const;
	Point operator/(Point const& other) const;
};