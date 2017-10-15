#pragma once
#include "Line.h"
#include <iostream>

namespace poly {
	class Polygon {
	public:
		Polygon(Point* p);
		Polygon();
		friend Polygon* operator+(Polygon& a, Point& p);
		friend Polygon operator+(Line& a, Point& b);
		void output();
	private:
		int num_points = 2;
		Point* points;
	};
}