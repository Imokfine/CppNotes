/**
 * @file ConvexHull.h
 * @brief Contains class definition for ConvexHull.
 * 		Needed for Assignment 5 in 5614 C++ programming.
 * 		Write the member function definitions in ConvexHull.cc
 * @author R. Morrin modified by Xueni Fu
 * @version 1.0
 * @date 2023-05-17
 */
#ifndef CONVEXHULL_H_AONEGHY7
#define CONVEXHULL_H_AONEGHY7
#include "point.h"

class ConvexHull
{
public:
    ConvexHull(std::vector<Point>::iterator beg, std::vector<Point>::iterator end);
    ConvexHull() = default;
    ~ConvexHull() = default; 			  	  // Destructor
    ConvexHull(const ConvexHull&) = default;    	  // Copy ctor
    ConvexHull(ConvexHull&&) = default; 	  	  // Move ctor
    ConvexHull& operator=(const ConvexHull&) = default;  // Copy assignment
    ConvexHull& operator=(ConvexHull&&) = default; 	  // Move assignment

    void merge_to_right(ConvexHull& right);
    std::vector<Point> generate_hull();

    std::vector<Point> get_points() const {
        return points;
    }

    std::vector<Point> get_hull() const {
        return hull;
    }

    // Move a vector of Points into the hull member variable
    void movehull(std::vector<Point>&& in) {
        hull = std::move(in);
    }

private:
    std::vector<Point> points;
    std::vector<Point> hull;
};

double calculate_ym(Point a, Point b, double xm);

#endif /* end of include guard: CONVEXHULL_H_AONEGHY7 */


