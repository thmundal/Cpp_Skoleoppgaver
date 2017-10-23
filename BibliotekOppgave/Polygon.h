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
		friend Polygon operator+(Line& a, Line&b);
		Polygon operator+(Polygon& b);
		void output();
		~Polygon();
	private:
		int num_points = 2;
		Point* points;
	};
}