#pragma once
#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

class Tuple {

protected:

	double x;
	double y;
	double z;
	double w;
	int type;

public:

	Tuple();
	Tuple(double x, double y, double z, int w);
	//void Point(double x = 0, double y = 0, double z = 0);
	//void Vector(double x = 0, double y = 0, double z = 0);

	double magnitude() const;
	Tuple normalize() const;
	double dot(Tuple const& u) const;
	Tuple cross(Tuple const& t, Tuple const& u) const;

	bool IsPoint() const;
	bool IsVector() const;
	bool IsColor() const;

	double getX() const;
	double getY() const;
	double getZ() const;
	double getW() const;
	int getType() const {
		return type;
	}

	vector<double> getAll() const {
		vector<double> temp = {x, y, z, w};
		return temp;
	}

	void Print() {
		cout << x << " ";
		cout << " " << y << " ";
		cout << " " << z << " ";
		cout << " " << w << endl;
	}

	//void operator=(Tuple const& other);
	//bool operator==(Tuple const& other) const;
	//Tuple operator+(Tuple const& other) const; //TODO: Remove
	//Tuple operator+(Tuple const& other) const;
	//Tuple operator-(Tuple other);
	//Tuple minus(Tuple me, Tuple other); //TODO: Fix this
	//Tuple operator-() const;
	//Tuple operator*(double num) const;
	//Tuple operator*(Tuple const& other) const;
	//Tuple operator/(double num) const;
	//Tuple operator/(Tuple const& other) const;

};


