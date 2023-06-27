/**
 * @file point.cc
 * @brief Member function definitions for point.h
 * @author Xueni Fu
 * @version 1.0
 * @date 2023-05-14
 */
#include <iostream>
#include "point.h"

bool Point::operator==(const Point& rhs) {
	return x == rhs.x && y == rhs.y;
}

bool cross_prod(Point p1, Point p2, Point p3) {

	// cross_product = (v1x * v2y) - (v1y * v2x)
	double cp = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	
	//return true if the the result is negative (or zero, for collinear points).
	//clockwise
	if (cp <= 0) { return true; }
	else { return false; }
}

void sort_points(std::vector<Point>& points) {
	std::sort(points.begin(), points.end(), 
		[](const Point& a, const Point& b)
		{
			if (a.x == b.x) {
				return a.y < b.y;
			}
			return a.x < b.x;
		}
	);
}

void write_to_file(std::string fn, std::vector<Point> pts) {
	std::ofstream file(fn);
	if (file.is_open()) {
		for (const Point& point : pts) {
			file << point.x << "," << point.y << std::endl;
		}
		file.close();
	}
	else {
		std::cerr << "Unable to open file: " << fn << std::endl;
	}
}

