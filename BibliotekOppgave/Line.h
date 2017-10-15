#pragma once
#include "Point.h"
#include <iostream>

namespace poly {
	class Line {
	private:
	public:
		Point points[2];
		Line(Point, Point);
		Line();
		friend Line operator+(Point& a, Point& b);
		void output();
	};
}