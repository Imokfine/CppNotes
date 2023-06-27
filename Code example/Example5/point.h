/**
 * @file point.h
 * @brief Class definition for Point class needed for 5614 Assignment 5.
 * 		Write the necessary function definitions in point.cc
 * @author R. Morrin modified by Xueni Fu
 * @version 1.0
 * @date 2023-05-17
 */
#ifndef POINT_H_OMJSZLDH
#define POINT_H_OMJSZLDH
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>

#include <boost/mpi.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>

 /**
  * @brief Simple structure to store coordinates of a point on the grid
  */
struct Point {
    double x;                                      //!< x-coordinate 
    double y;                                      //!< y-coordinate 

    Point() = default;
    Point(double inx, double iny) : x{ inx }, y{ iny } {};  //!< Constructor

    // Write the definition of this in point.cc
    bool operator==(const Point& rhs);

    // Boost MPI
    template <typename Archive>
    void serialize(Archive& ar, unsigned /*ver*/) {
        ar& x;
        ar& y;
    };
};

/**
 * @brief Overloading output stream operator for a Point.
 * The operator should simply print the x and y coordinates of Point "in"
 *
 * @param os    Reference to output stream
 * @param in    Reference to Point which we want to print.
 *
 * @return      Reference to output stream
 */
inline std::ostream& operator<<(std::ostream& os, const Point& in) {
    os << std::fixed << std::setw(9) << in.x << ", " << std::setw(9) << in.y;
    return os;
}

// Write the definition of the 3 below functions in point.cc
void write_to_file(std::string fn, std::vector<Point> pts);
bool cross_prod(Point p1, Point p2, Point p3);
void sort_points(std::vector<Point>& points);

//Boost MPI
template void Point::serialize<boost::mpi::packed_iarchive>(boost::mpi::packed_iarchive&, unsigned);

template void Point::serialize<boost::mpi::packed_oarchive>(boost::mpi::packed_oarchive&, unsigned); 


#endif /* end of include guard: POINT_H_OMJSZLDH */


