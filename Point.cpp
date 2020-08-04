#include "Point.h"

// assign
void Point::operator=(Point const& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}
// equality
bool Point::operator==(Point const& other) const {
	if (x == other.x && y == other.y && z == other.z) {
		return true;
	}
	else {
		return false;
	}
}
// addition : Point(1) + Point(1) is invalid
Point Point::operator+(Point const& other) const {
	double _x = x + other.x;
	double _y = y + other.y;
	double _z = z + other.z;
	return Point(_x, _y, _z);
}
Point Point::operator+(Vector const& other) const {
	double _x = x + other.getX();
	double _y = y + other.getY();
	double _z = z + other.getZ();
	return Point(_x, _y, _z);
}
//subtracting tuples : //Vector(0) - Point(1) is invalid
Point Point::minus(Point me, Point other) {

	double _x = me.getX() - other.getX();
	double _y = me.getY() - other.getY();
	double _z = me.getZ() - other.getZ();

	return Point(_x, _y, _z);
}
Vector Point::operator-(Point other) {

	double _x = x - other.x;
	double _y = y - other.y;
	double _z = z - other.z;

	return Vector(_x, _y, _z);
}
//negating tuples
Point Point::operator-() const {

	double _x = 0 - x;
	double _y = 0 - y;
	double _z = 0 - z;

	return Point(_x, _y, _z);
}
//scalar multiplication
Point Point::operator*(double num) const {

	double _x = x * num;
	double _y = y * num;
	double _z = z * num;

	return Point(_x, _y, _z);
}
Point Point::operator*(Point const& other) const {

	double _x = x * other.x;
	double _y = y * other.y;
	double _z = z * other.z;

	return Point(_x, _y, _z);
}
//scalar division
Point Point::operator/(double num) const {

	double _x = x / num;
	double _y = y / num;
	double _z = z / num;

	return Point(_x, _y, _z);
}
Point Point::operator/(Point const& other) const {

	double _x = x / other.x;
	double _y = y / other.y;
	double _z = z / other.z;

	return Point(_x, _y, _z);
}


