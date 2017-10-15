#include "Line.h"


namespace poly {
	Line::Line(Point a, Point b) {
		points[0] = a;
		points[1] = b;
	}

	Line::Line() {

	}

	void Line::output() {
		std::cout << "En linje satt opp av ";
		points[0].output();
		std::cout << " og ";
		points[1].output();
		std::cout << std::endl;
	}

	Line operator+(Point& a, Point& b) {
		return Line(a, b);
	}
}