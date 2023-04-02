/**
 * @file assignment2a.cc
 * @brief  C++ Assignment2a
 * @author Xueni Fu
 * @version 1.0
 * @date 2023-02-24
 */

#include <iostream>
#include <iomanip>

// Use this, and std::numbers::pi if you have C++20
// #include <numbers>

// Use this if you don't have C++20
#include <cmath>
const double A = M_PI;

/**
 * @brief Shape struct for assignment2a. This will be a base struct you 
 * 	can derive the Cube and Cylinder structs from. You don't need to change this struct.
 */
struct Shape
{
	Shape () 			= delete; 	// Delete default constructor 
	// Overloaded Constructor
	Shape (double v, double sa) : volume {v}, surface_area{sa} {
		std::cout << "Constructing Shape with volume = " << volume 
			<< " and surface area = " << surface_area << std::endl; 
	}; 	
	// Destructor
	~Shape () {
		std::cout << "Destroying Shape with volume = " << volume
			<< " and surface area = " << surface_area << std::endl; 
	}

	Shape(const Shape&) 		= default; 	// Copy constructor
	Shape(Shape&&) 			= default; 	// Move constructor. Will actually be the same as copy for this class

	// Delete assignment operations
	Shape& operator=(const Shape &) = delete;
	Shape& operator=(Shape &&) 	= delete;

	// Member variables. 
	const double volume; 		//!< Holds the volume of the Shape
	const double surface_area; 	//!< Holds surface area of the Shape
};

// TODO:
// (1) Write struct Cube which inherits from Shape. It will have a const member variable "side"
// (2) Write struct Cylinder which inherits from Shape. It will have const member variables "radius" and "height"

struct Cube : public Shape
{
	// Overloaded Constructor
	Cube(double s) : Shape{s*s*s, 6*s*s}, side{s} {
		std::cout << "Constructing Cube with side = " << side << std::endl;
	}

	// Destructor
	~Cube() {
		std::cout << "Destroying Cube with side = " << side << std::endl;
	}

	Cube() = delete; // Delete default constructor

	Cube(const Cube&) = default; 	// Copy constructor
	Cube(Cube&&) = default; // Move constructor

	// Delete assignment operations
	Cube& operator=(const Cube&) = delete; // Copy assignment operator
	Cube& operator=(Cube&&) = delete; // Move assignment operator

	// Member variables
	const double side;
};

struct Cylinder : public Shape
{
	// Overloaded Constructor
	Cylinder(double r, double h) : Shape{ A * r * r * h,2 * A * r * (r + h) }, radius{ r }, height{ h } {
		std::cout << "Constructing Cylinder with radius = " << radius << " and height = " << height << std::endl;
	}

	// Destructor
	~Cylinder() {
		std::cout << "Destroying Cylinder with radius = " << radius << " and height = " << height << std::endl;
	}

	Cylinder() = delete; // Delete default constructor

	Cylinder(const Cylinder&) = default; 	// Copy constructor
	Cylinder(Cylinder&&) = default; // Move constructor

	// Delete assignment operations
	Cylinder& operator=(const Cylinder&) = delete; // Copy assignment operator
	Cylinder& operator=(Cylinder&&) = delete; // Move assignment operator

	// Member variables
	const double radius;
	const double height;
};

/// END: You shouldn't need to edit below here.

int main()
{
	const int w1{26}, w2{10}; 	// For formatting output
	std::cout << std::fixed << std::setprecision(3);
	
	// Cube {side_length}
	const Cube cube {1.2};
	std::cout<<std::setw(w1) << std::left << "\nSide of cube:"       << std::setw(w2) << std::right << cube.side         << '\n' 
		<< std::setw(w1) << std::left << "Volume of cube:"       << std::setw(w2) << std::right << cube.volume       << '\n' 
		<< std::setw(w1) << std::left << "Surface area of cube:" << std::setw(w2) << std::right << cube.surface_area << "\n\n\n";

	// Cylinder {radius, height}
	const Cylinder cylinder {3.4, 5.0};
	std::cout<<std::setw(w1) << std::left << "\nHeight of cylinder:"     << std::setw(w2) << std::right << cylinder.height       << '\n' 
		<< std::setw(w1) << std::left << "Radius of cylinder:"       << std::setw(w2) << std::right << cylinder.radius       << '\n' 
		<< std::setw(w1) << std::left << "Volume of cylinder:"       << std::setw(w2) << std::right << cylinder.volume       << '\n' 
		<< std::setw(w1) << std::left << "Surface area of cylinder:" << std::setw(w2) << std::right << cylinder.surface_area << "\n\n\n";

	return 0;
}
