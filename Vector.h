#pragma once
#include "Tuple.h"

class Vector : public Tuple {

public:

	Vector(double r = 0, double g = 0, double b = 0) {
		x = r;
		y = g;
		z = b;
		w = 0;
		type = 0;
	}

	void operator=(Vector const& other);
	bool operator==(Vector const& other) const;
	Vector operator+(Vector const& other) const;
	//Vector + Point
	Vector operator-(Vector const& other) const;
	Vector operator-() const;
	Vector operator*(double num) const;
	Vector operator*(Vector const& other) const;
	Vector operator/(double num) const;
	Vector operator/(Vector const& other) const;


	Vector normalize() const {
		double mag = this->magnitude();
		return Vector(x / mag,
					  y / mag,
					  z / mag);	
	}
	Vector reflect(Vector incoming, Vector normal) {
	
		return incoming - normal * 2 * incoming.dot(normal);
	}
	void setW(double w) {
	
		this->w = w;	
	}






























	Vector scale(double x) {
	
		Vector temp;

		temp.x *= x;
		temp.y *= x;
		temp.z *= x;
		temp.w *= x;

		return temp;
	}

	//double dot(Vector const& u) const {

	//	return this->x * u.getX() +
	//		this->y * u.getY() +
	//		this->z * u.getZ() +
	//		this->w * u.getW();
	//};


	//double dot(Point const& u) const {

	//	return this->x * u.getX() +
	//		this->y * u.getY() +
	//		this->z * u.getZ() +
	//		this->w * u.getW();
	//};





};

