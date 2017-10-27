#include "Polygon.h"


namespace poly {
	Polygon::Polygon() {
	}

	Polygon::Polygon(std::vector<Point> _points) {
		points = _points;
	}

	Polygon operator+(Polygon& a, Point& p) {
		a.points.push_back(p);
		return a;
	}

	void Polygon::output() {
		std::cout << "Et polygon bygd opp av: " << std::endl;
		for (Point p : points) {
			p.output();
		}
		std::cout << std::endl;
	}

	Polygon operator+(Line a, Point b) {
		return Polygon(
			std::vector<Point> 
			{
				a.points.at(0),
				a.points.at(1),
				b
			});
	}

	Polygon operator+(Line a, Line b) {
		return Polygon(
			std::vector<Point> 
			{ 
				a.points.at(0), 
				a.points.at(1),
				b.points.at(0),
				b.points.at(1)
			});
	}

	Polygon operator+(Polygon a, Line b) {
		std::vector<Point> new_points = a.points;
		new_points.push_back(b.points.at(0));
		new_points.push_back(b.points.at(1));
		return Polygon(new_points);
	}

	Polygon Polygon::operator+(Polygon& b) {
		std::vector<Point> points = this->points;

		for (Point p : b.points) {
			points.push_back(p);
		}

		return Polygon(points);
	}
}