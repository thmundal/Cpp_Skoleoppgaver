#pragma once
#include "Point.h"
#include <iostream>
#include <vector>

namespace poly {
	class Line {
	private:
	public:
		std::vector<Point> points;

		Line(Point, Point);
		Line();
		friend Line operator+(Point& a, Point& b);
		void output();
	};
}