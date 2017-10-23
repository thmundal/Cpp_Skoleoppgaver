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
		std::cout << "Et polygon bygd opp av: " << std::endl;
		for (int i = 0; i < num_points; i++) {
			points[i].output();
		}
		std::cout << std::endl;
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

	Polygon operator+(Line& a, Line& b) {
		Point* points = new Point[4];
		points[0] = a.points[0];
		points[1] = a.points[1];
		points[2] = b.points[0];
		points[3] = b.points[1];

		Polygon out = Polygon(points);
		out.num_points = 4;
		return out;
	}

	Polygon Polygon::operator+(Polygon& b) {
		Point* points = new Point[this->num_points + b.num_points];

		for (int i = 0; i < (this->num_points + b.num_points); i++) {
			if (i < this->num_points) {
				points[i] = this->points[i];
			}
			else {
				points[i] = b.points[i - this->num_points];
			}
		}

		Polygon out = Polygon(points);
		out.num_points = (this->num_points + b.num_points);
		return out;
	}

	Polygon::~Polygon() {
		delete[] points;
	}
}