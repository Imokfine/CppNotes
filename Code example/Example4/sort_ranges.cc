/**
 * @file sort_ranges.cc
 * @brief Q4 for 5614 E4 2023
 * @author Xueni Fu modified from R. Morrin
 * @version 1.0
 * @date 2023-04-14
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Coord
{
	Coord(char c, int x, int y) : c{ c }, x{ x }, y{ y } {};
	~Coord() = default;
	Coord(Coord const&) = default;
	Coord& operator=(Coord const&) = default;
	Coord(Coord&&) = default;
	Coord& operator=(Coord&&) = default;

	char c;
	int x;
	int y;
};


int main()
{

	std::vector<Coord> A{};

	A.emplace_back('a', 2, 2);
	A.emplace_back('b', -1, 2);
	A.emplace_back('c', 3, 1);
	A.emplace_back('d', 3, 7);
	A.emplace_back('e', 1, -4);

	// Original vector
	std::cout << "Before sorting\n";
	std::ranges::for_each(A, [](Coord const& c) {std::cout << c.c << std::setw(9) << c.x << std::setw(9) << c.y << "\n";});

	// Sort by-x-then-y
	std::ranges::sort(A, [](Coord const& a, Coord const& b) {return a.x < b.x || (a.x == b.x && a.y < b.y);});
	std::cout << "\nAfter sorting x_then_y\n";
	std::ranges::for_each(A, [](Coord const& c) {std::cout << c.c << std::setw(9) << c.x << std::setw(9) << c.y << "\n";});

	// Sort by-y-then-x
	std::ranges::sort(A, [](Coord const& a, Coord const& b) {return a.y < b.y || (a.y == b.y && a.x < b.x); });
	std::cout << "\nAfter sorting y_then_x\n";
	std::ranges::for_each(A, [](Coord const& c) {std::cout << c.c << std::setw(9) << c.x << std::setw(9) << c.y << "\n";});

	return 0;
}

