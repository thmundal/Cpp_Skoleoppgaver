#include "Polygon.h"


namespace poly {
	Polygon::Polygon() {

	}

	Polygon::Polygon(Point* _points) {
		points = _points;
	}

	Polygon* operator+(Polygon& a, Point& p) {
		a.num_points++;
		Point* new_points = new Point[a.num_points];

		int i;
		for (i = 0; i < a.num_points - 2; i++) {
			new_points[i] = a.points[i];
		}

		new_points[a.num_points - 1] = a.points[i];
		delete a.points;
		a.points = new_points;
		return &a;
	}

	void Polygon::output() {
		std::cout << "Et polygon bygd opp av: ";
		for (int i = 0; i < num_points; i++) {
			points[i].output();
		}
	}

	Polygon operator+(Line& a, Point& b) {
		Point* points = new Point[3];
		points[0] = a.points[0];
		points[1] = a.points[1];
		points[2] = b;

		Polygon out = Polygon(points);
		out.num_points = 3;
		return out;
	}

}