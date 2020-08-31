#pragma once
#include <vector>
#include "Ray.h"
#include "Point.h"
#include "Vector.h"
#include "Matrix.h"
//#include "Intersection.h"
#include "Material.h"
#include "Light.h"

using namespace std;

class Shape {

protected:

	string type;

	int currID = 0;
	int ID;
	Point position;
	Material material;
	Matrix transformation = Matrix({{1, 0, 0, 0},
									{0, 1, 0, 0},
									{0, 0, 1, 0},
									{0, 0, 0, 1}});

public:

	Shape() {
		ID = currID++;
		position = Point(0, 0, 0);
		material = Material();
	}

	int getID() {
		return ID;
	}
	void setID(int val) {
		ID = val;
	}
	
	Point getPosition() {
		return position;
	}


	void Print() {
	
		cout << "Type: " << type << endl;
		cout << "RayObject: " << ID << endl;
	
	}


	std::vector<double> intersect(Ray newray) {

		Ray ray = newray.transform(transformation.inverse());

		std::vector<double> temp;

		Point sphereToRay = sphereToRay.minus(ray.getOrigin(), position);
		//cout << "Sphere to Ray: ";
		//sphereToRay.Print();
		double a = ray.getDirection().dot(ray.getDirection());
		//cout << "a: " << a << endl;
		double b = 2 * ray.getDirection().dot(sphereToRay);
		//cout << "b: " << b << endl;
		double c = sphereToRay.dot(sphereToRay) - 1;
		//cout << "c: " << c << endl;
		double discriminant = b * b - 4 * a * c;
		//cout << "Discriminent: " << discriminant << endl;

		//cout << "Disc: " << discriminant << endl;
		if (discriminant < 0) {
			return temp; //return empty vector
		}
		double t1 = (-b - sqrt(discriminant)) / (2 * a);
		double t2 = (-b + sqrt(discriminant)) / (2 * a);


		//cout << "T1: " << t1 << endl;
		//cout << "T2: " << t2 << endl;

		temp.push_back(t1);
		temp.push_back(t2);

		return temp;
	}




	void setTransform(Matrix transformation) {
		this->transformation = transformation;
	}


	Matrix getTransform() {
		return transformation;
	}


	void setMaterial(Material material) {
		this->material = material;
	}

	Material getMaterial() {
		return material;
	}

	Vector normalAt(Point world) {

		Point objectPoint = transformation * world;
		Vector objectNormal = Vector(objectPoint - Point(0, 0, 0));
		Vector worldNormal = transformation.inverse().transpose() * objectNormal;
		worldNormal.setW(0);

		//cout << "IN  NORMALAT" << endl;
		return	worldNormal.normalize();
		//Vector
	}

	Color lighting(Point position, Light light, Vector eye, Vector normal) {
		
		Color effectiveColor = material.getColor() * light.getIntensity();
		material.Print();
		Vector lightVec = Vector(light.getPosition() - position).normalize();
		Color ambientColor = effectiveColor * material.getAmbient();
		Color diffuseColor;
		Color specularColor;

		double lightDotNormal = lightVec.dot(normal);
		if (lightDotNormal < 0) {
			diffuseColor = Color(0, 0, 0);
			specularColor = Color(0, 0, 0);
		}
		else {

			diffuseColor = effectiveColor * material.getDiffuse() * lightDotNormal;
			Vector reflect = lightVec.reflect(-lightVec, normal);
			double reflectDotEye = reflect.dot(eye);

			if (reflectDotEye <= 0) {
				specularColor = Color(0, 0, 0);
			}
			else {
				double factor = pow(reflectDotEye, material.getShine());
				specularColor = light.getIntensity() * material.getSpecular() * factor;
			}
		}
		//cout << "IN LIGHTING" << endl;
		//ambientColor.Print();
		//diffuseColor.Print();
		//specularColor.Print();
		////cout << "-------------------" << endl;
		return ambientColor + diffuseColor + specularColor;
	}


	/*

	public:

		Sphere(double radius = 1) {

			ID = currID++;
			position = Point(0, 0, 0);
			this->radius = radius;
			material = Material();
		}


		double getRadius() {
			return radius;
		}

		bool operator==(Sphere other) {
			if (currID == other.getID() && position == other.getPosition()) {
				return true;
			}
			return false;
		}
	*/

};

