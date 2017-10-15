#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include <iostream>

using namespace poly;

int main() {
	Point point1 = Point(0, 0);
	Point point2 = Point(0, 10);

	Line line1 = point1 + point2;

	Point point3 = Point(10, 10);
	Polygon polygon1 = line1 + point3;


	std::cout << "Settet med punkter, linjer og polygoner er:" << std::endl;
	
	point1.output();
	std::cout << std::endl;
	point2.output();
	std::cout << std::endl;


	line1.output();
	std::cout << std::endl;

	point3.output();
	std::cout << std::endl;

	polygon1.output();

	std::cout << std::endl << "Trykk enter for å avslutte";
	std::cin.get();
}