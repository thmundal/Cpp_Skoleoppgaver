#pragma once
#include <iostream>

namespace poly {
	class Point {
	private:
		int x, y;
	public:
		Point(int, int);
		Point();
		void output();
	};
}