#include "Vector.h"

// assign tuples
void Vector::operator=(Vector const& other) {

	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}
// compare tuples
bool Vector::operator==(Vector const& other) const {
	if (x == other.x && y == other.y && z == other.z) {
		return true;
	}
	else {
		return false;
	}
}
//add tuples : point + Point is invalid
Vector Vector::operator+(Vector const& other) const {
	double _x = x + other.x;
	double _y = y + other.y;
	double _z = z + other.z;
	return Vector(_x, _y, _z);
}
//subtracting tuples : Vector - Point is invalid
Vector Vector::operator-(Vector const& other) const {

	double _x = x - other.x;
	double _y = y - other.y;
	double _z = z - other.z;

	return Vector(_x, _y, _z);
}
//negating tuples
Vector Vector::operator-() const {

	double _x = 0 - x;
	double _y = 0 - y;
	double _z = 0 - z;

	return Vector(_x, _y, _z);
}
//scalar multiplication
Vector Vector::operator*(double num) const {

	double _x = x * num;
	double _y = y * num;
	double _z = z * num;

	return Vector(_x, _y, _z);
}
Vector Vector::operator*(Vector const& other) const {

	double _x = x * other.x;
	double _y = y * other.y;
	double _z = z * other.z;

	return Vector(_x, _y, _z);
}
//scalar division
Vector Vector::operator/(double num) const {

	double _x = x / num;
	double _y = y / num;
	double _z = z / num;

	return Vector(_x, _y, _z);
}
Vector Vector::operator/(Vector const& other) const {

	double _x = x / other.x;
	double _y = y / other.y;
	double _z = z / other.z;

	return Vector(_x, _y, _z);
}