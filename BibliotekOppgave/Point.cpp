#include "Point.h"

namespace poly {
	Point::Point(int _x, int _y) {
		x = _x;
		y = _y;
	}

	Point::Point() {

	}

	void Point::output() {
		std::cout << "Et punkt med koordinater x=" << x << " y=" << y;
	}
}