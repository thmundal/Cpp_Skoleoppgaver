#pragma once
#include "Line.h"
#include <iostream>
#include <vector>

namespace poly {
	class Polygon {
	public:
		Polygon(std::vector<Point> p);
		Polygon();
		friend Polygon operator+(Polygon& a, Point& p);
		friend Polygon operator+(Line a, Point b);
		friend Polygon operator+(Line a, Line b);
		friend Polygon operator+(Polygon a, Line b);
		Polygon operator+(Polygon& b);
		void output();
	private:
		std::vector<Point> points;
	};
}