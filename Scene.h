#pragma once
#include "Light.h"
#include "Sphere.h"
#include "Shape.h"
#include "Intersection.h"
#include "Computations.h"
#include "Material.h"
#include "Color.h"

#include <vector>

class Scene {
	vector<Light> lights;
	vector<Sphere> shapes;

public:
	Scene() {}

	void defaultScene() {
		Light light = Light(Color(1, 1, 1), Point(-10, 10, -10));
		lights.push_back(light);

		Sphere s1 = Sphere();
		Material mat = Material(Color(0.8, 1.0, 0.6));
		mat.setDiffuse(0.7);
		mat.setSpecular(0.2);
		s1.setMaterial(mat);
		
		Sphere s2 = Sphere();
		Matrix scale = scale.scalingMatrix(0.5, 0.5, 0.5);
		s2.setTransform(scale);

		shapes.push_back(s1);
		shapes.push_back(s2);
	}



	Scene(vector<Light> lights, vector<Sphere> shapes) {
		this->lights = lights;
		this->shapes = shapes;
	}

	void replaceLight(Light light) {
		lights[0] = light;
	}

	void addLight(Light light) {
		lights.push_back(light);
	}
	void addShape(Sphere shape) {
		shapes.push_back(shape);
	}

	//vector<Shape> getShapes() {
	//	return shapes;
	//}
	void setShapes(vector<Sphere> shapes) {
		this->shapes = shapes;
	}


	std::vector<Intersection> intersectWorld(Ray newray) {

		std::vector<Intersection> inters;

		for (Sphere r : shapes) {

			std::vector<double> temp = r.intersect(newray);

			for (int i = 0; i < temp.size(); i++) {
				inters.push_back(Intersection(r, temp[i]));
			}
		}
		return inters;
	}

	vector<Sphere> getSpheres() {
		return shapes;
	}

	Intersection Hit(vector<Intersection> intersections) {

		Intersection nullInter;

		if (intersections.size() == 0) {
			//cout << "NULL " << endl;
			return nullInter;
		}

		Intersection inter = nullInter;
		double min = 999;
		//the lowest non-negative integers

		for (Intersection x : intersections) {
			if (x.getT() >= 0) {
				if (x.getT() < min) {
					min = x.getT();
					inter = x;
				}
			}
		}

		if (min == 999) {
			return nullInter;
		}

		return inter;

	}


	Color shadeHit(Computations comp) {
	
		Color finalColor = Color(0, 0, 0);

		for (int i = 0; i < lights.size(); i++) {
		
			finalColor = finalColor + comp.getShape().lighting(comp.getPoint(), lights[i], comp.getEye(), comp.getNormal());	
		}

		return finalColor;
		//return comp.getShape().lighting(comp.getPoint(), lights[lights.size()-1], comp.getEye(), comp.getNormal());
	}


	//Color colorAt(Ray ray) {
	//	
	//	vector<Intersection> hits = intersectS(ray);
	//	Intersection hit = Hit(hits);
	//	Computations c = Computations(hit, ray);
	//	Color col = shadeHit(c);

	//	return col;
	//
	//}

};
