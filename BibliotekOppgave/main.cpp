#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include <iostream>
#include <locale>

using namespace poly;

int main() {
	Point point1 = Point(0, 0, 0);
	Point point2 = Point(0, 10, 3);
	Point point3 = Point(10, 10, -5);
	Point point4 = Point(20, 30, 140);

	Line line1 = point1 + point2;

	Polygon polygon1 = line1 + point3;

	Line line2 = Line(Point(10, 10, -50), Point(10, 0, 32));
	Polygon polygon2 = line1 + line2;

	Polygon p1_cpy = polygon1;
	Polygon polygon3 = p1_cpy + polygon2 + point4;

	std::cout << "Settet med punkter, linjer og polygoner er:" << std::endl;
	
	std::cout << "Point1:" << std::endl;
	point1.output();
	std::cout << std::endl;

	std::cout << "Point2:" << std::endl;
	point2.output();
	std::cout << std::endl;

	std::cout << "Point3:" << std::endl;
	point3.output();
	std::cout << std::endl;

	std::cout << "Point4:" << std::endl;
	point4.output();
	std::cout << std::endl;

	std::cout << "Line1: (point1 + point2)" << std::endl;
	line1.output();

	std::cout << "Line2: (Definer i constructor med disse punktene)" << std::endl;
	line2.output();

	std::cout << "Polygon1 (line1 + point3):" << std::endl;
	polygon1.output();

	std::cout << "Polygon2 (line1 + line2):" << std::endl;
	polygon2.output();

	std::cout << "Polygon3 (polygon1 + polygon2 + point4)" << std::endl;
	polygon3.output();

	std::wcout << L"Trykk enter for " << char(134) << " avslutte";
	
	std::cin.get();

	return 0;
}