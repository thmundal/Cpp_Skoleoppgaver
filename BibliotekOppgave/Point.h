#pragma once
#include <iostream>

namespace poly {
	class Point {
	private:
		int x = 0, y = 0, z = 0;
	public:
		Point(int x, int y);
		Point(int x, int y, int z);
		Point();
		void output();
	};
}