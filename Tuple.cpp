#include "Tuple.h"
#include "Point.h"
#include "Vector.h"

Tuple::Tuple() {};
Tuple::Tuple(double x, double y, double z, int w) {
	if (w = 1) {
		Point(x, y, z);
	}
	else {
		Vector(x, y, z);
	}
}
//void Tuple::Point(double x = 0, double y = 0, double z = 0) {
//	this->x = x;
//	this->y = y;
//	this->z = z;
//	this->w = 1;
//}
//void Tuple::Vector(double x = 0, double y = 0, double z = 0) {
//	this->x = x;
//	this->y = y;
//	this->z = z;
//	this->w = 0;
//}

bool Tuple::IsPoint() const {
	if (w == 1) {
		return true;
	}
	else {
		return false;
	}
}
bool Tuple::IsVector() const {
	if (w == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Tuple::IsColor() const {

	if (w == 2) {
		return true;
	}
	else {
		return false;
	}
}

//magnitude (v): length of a tuple
double Tuple::magnitude() const {
	return sqrt(pow(x, 2) + 
				pow(y, 2) + 
				pow(z, 2));
}
//normalization: converting a vector to a unit vector (vector of magnitude 1) 
Tuple Tuple::normalize() const {

	double mag = magnitude();
	return Tuple(x / mag,
				 y / mag,
				 z / mag,
				 w / mag);
}
//dot product: the smaller the dot product the larger the angle between vectors 
double Tuple::dot(Tuple const& u) const {

	return this->x * u.x +
		   this->y * u.y +
		   this->z * u.z;
}
//cross product: returns vector perpendicular to both vectors
Tuple Tuple::cross(Tuple const& t, Tuple const& u) const {
	Vector temp = Vector(t.y / u.z - t.z / u.y,
						 t.z / u.x - t.x / u.z,
						 t.x / u.y - t.y / u.x);
	return temp;
}

//Getters
double Tuple::getX() const {
	return x;
}
double Tuple::getY() const {
	return y;
}
double Tuple::getZ() const {
	return z;
}
double Tuple::getW() const {
	return w;
}

//// assign
//void Tuple::operator=(Tuple const& other) {
//
//	this->x = other.x;
//	this->y = other.y;
//	this->z = other.z;
//}
//// equality
//bool Tuple::operator==(Tuple const& other) const {
//	if (x == other.x && y == other.y && z == other.z) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//// addition : Tuple(1) + Tuple(1) is invalid
//Tuple Tuple::operator+(Tuple const& other) const {
//	double _x = x + other.x;
//	double _y = y + other.y;
//	double _z = z + other.z;
//	return Tuple(_x, _y, _z);
//}
//Tuple Tuple::operator+(Vector const& other) const {
//	double _x = x + other.getX();
//	double _y = y + other.getY();
//	double _z = z + other.getZ();
//	return Tuple(_x, _y, _z);
//}
////subtracting tuples : //Vector(0) - Tuple(1) is invalid
//Tuple Tuple::minus(Tuple me, Tuple other) {
//
//	double _x = me.getX() - other.getX();
//	double _y = me.getY() - other.getY();
//	double _z = me.getZ() - other.getZ();
//
//	return Tuple(_x, _y, _z);
//}
//Vector Tuple::operator-(Tuple other) {
//
//	double _x = x - other.x;
//	double _y = y - other.y;
//	double _z = z - other.z;
//
//	return Vector(_x, _y, _z);
//}
////negating tuples
//Tuple Tuple::operator-() const {
//
//	double _x = 0 - x;
//	double _y = 0 - y;
//	double _z = 0 - z;
//
//	return Tuple(_x, _y, _z);
//}
////scalar multiplication
//Tuple Tuple::operator*(double num) const {
//
//	double _x = x * num;
//	double _y = y * num;
//	double _z = z * num;
//
//	return Tuple(_x, _y, _z);
//}
//Tuple Tuple::operator*(Tuple const& other) const {
//
//	double _x = x * other.x;
//	double _y = y * other.y;
//	double _z = z * other.z;
//
//	return Tuple(_x, _y, _z);
//}
////scalar division
//Tuple Tuple::operator/(double num) const {
//
//	double _x = x / num;
//	double _y = y / num;
//	double _z = z / num;
//
//	return Tuple(_x, _y, _z);
//}
//Tuple Tuple::operator/(Tuple const& other) const {
//
//	double _x = x / other.x;
//	double _y = y / other.y;
//	double _z = z / other.z;
//
//	return Tuple(_x, _y, _z);
//}

