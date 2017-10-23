#include "Line.h"


namespace poly {
	Line::Line(Point a, Point b) {
		points.push_back(a);
		points.push_back(b);
	}

	Line::Line() {

	}

	void Line::output() {
		std::cout << "En linje satt opp av " << std::endl;
		points[0].output();
		points[1].output();
		std::cout << std::endl;
	}

	Line operator+(Point& a, Point& b) {
		return Line(a, b);
	}
}