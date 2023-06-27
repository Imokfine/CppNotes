/**
 * @file ConvexHull.cc
 * @brief Member function definitions for ConvexHull.h 
 * @author Xueni Fu
 * @version 1.0
 * @date 2023-05-15
 */
#include <iostream>
#include "ConvexHull.h"

ConvexHull::ConvexHull(std::vector<Point>::iterator beg, std::vector<Point>::iterator end) {
	std::vector<Point>::iterator iter;
	for (iter = beg; iter != end; iter++) {
		points.push_back(*iter);
	}
}

std::vector<Point> ConvexHull::generate_hull() {

    // Return an empty hull if there are no points
    if (points.empty()) {
        return hull;  
    }

    // Add the leftmost point to the hull
    hull.push_back(points[0]);  

    // Find the points on the upper half of the convex hull
    for (size_t i = 1; i < points.size(); i++) {
        while (hull.size() >= 2 && !cross_prod(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) {
            hull.pop_back();  // Remove points that are not on the upper half of the hull
        }
        hull.push_back(points[i]);
    }

    // Reverse the vector to find the points on the lower half of the convex hull
    std::reverse(points.begin(), points.end());

    // Find the points on the lower half of the convex hull
    size_t upper_hull_size = hull.size();
    for (size_t i = 1; i < points.size(); i++) {
        while (hull.size() > upper_hull_size && !cross_prod(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) {
            hull.pop_back();  // Remove points that are not on the lower half of the hull
        }
        hull.push_back(points[i]);
    }

    return hull;
}

void ConvexHull::merge_to_right(ConvexHull& right) {

    hull.pop_back();
    right.hull.pop_back();

    //Split left hull into upperand lower hulls.
    std::vector<Point> upper_left_hull;
    std::vector<Point> lower_left_hull;

    //Split right hull into upperand lower hulls.
    std::vector<Point> upper_right_hull;
    std::vector<Point> lower_right_hull;


    // Find rightmost point and leftmost point
    Point rightmost_left = hull[0];
    Point leftmost_right = right.hull[0];
    double rm = hull[0].x;
    double lm = right.hull[0].x;
    for (Point point : hull) {
        if (point.x > rm) {
            rightmost_left = point;
            rm = rightmost_left.x;
        }
    }
    for (Point point : right.hull) {
        if (point.x < lm) {
            leftmost_right = point;
            lm = leftmost_right.x;
        }
    }

    /*
    std::cout << "rightmost_left = " << rightmost_left.x << "," << rightmost_left.y << "\n";
    std::cout << "leftmost_right = " << leftmost_right.x << "," << leftmost_right.y << "\n";
    */

    // Splitting into upper and lower hulls
    // The extreme x−coordinate Points in each hull will be in both upper and lower hulls.
    
    for (Point point : hull) {
        if (point.y >= rightmost_left.y) {
            upper_left_hull.push_back(point);
        }
        else {
            lower_left_hull.push_back(point);
        }
    }
    
    for (Point point : right.hull) {
        if (point.y >= leftmost_right.y) {
            upper_right_hull.push_back(point);
        }
        else {
            lower_right_hull.push_back(point);
        }
    }

    lower_left_hull.push_back(rightmost_left);
    lower_right_hull.push_back(leftmost_right);

    sort_points(upper_left_hull);
    sort_points(upper_right_hull);
    sort_points(lower_left_hull);
    sort_points(lower_right_hull);

    std::reverse(upper_left_hull.begin(), upper_left_hull.end());
    std::reverse(lower_left_hull.begin(), lower_left_hull.end());

    /*
    write_to_file(std::string("upper_left_hull.txt"), upper_left_hull);
    write_to_file(std::string("lower_left_hull.txt"), lower_left_hull);
    write_to_file(std::string("upper_right_hull.txt"), upper_right_hull);
    write_to_file(std::string("lower_right_hull.txt"), lower_right_hull);
    */

    // Define a vertical line at arbitrary xm between then.
    double xm = (rightmost_left.x + leftmost_right.x) / 2;

    // Calculate ym
    double ym = calculate_ym(rightmost_left, leftmost_right, xm);

    double yi = ym;
    int reject = 0;
    bool shouldBreak = false;
    int switch_to_right = 1;
    Point solution_left = rightmost_left;
    Point solution_right = leftmost_right;

    auto itrul = upper_left_hull.begin();
    auto itrur = upper_right_hull.begin();
    auto itrll = lower_left_hull.begin();
    auto itrlr = lower_right_hull.begin();


    // Rotate around upper hull
    // The outer loop rotate around the points on the left
    while(itrul != upper_left_hull.end()) {        

        if (switch_to_right == 0) {
            itrul++;
            yi = calculate_ym(*itrul, solution_right, xm);
            if (yi > ym) {
                ym = yi;
                solution_left = *itrul;
                reject = 0;               
            }
            else {
                reject++;
                switch_to_right = 1;
                itrul--;
            }

            
        }

        // Break if get two rejections in a row
        if (reject >= 2 || shouldBreak == true) {
            break;
        }

        // The inner loop rotate around the points on the right
        if (switch_to_right == 1) {
            while (itrur != upper_right_hull.end()) {
                itrur++;
                yi = calculate_ym(solution_left, *itrur, xm);
                if (yi > ym) {
                    ym = yi;
                    solution_right = *itrur;
                    reject = 0;                   
                }
                else {
                    reject++;
                    switch_to_right = 0;
                    itrur--;
                    break;
                }

                if (reject >= 2) {
                    shouldBreak = true;
                    break;
                }

                
            }
        }

        // Break if get two rejections in a row
        if (reject >= 2 || shouldBreak == true) {
            break;
        }
    }    

    double ym2 = calculate_ym(rightmost_left, leftmost_right, xm);

    yi = ym2;
    reject = 0;
    shouldBreak = false;
    switch_to_right = true;
    Point solution_left2 = rightmost_left;
    Point solution_right2 = leftmost_right;

    // Rotate around lower hull
    // The outer loop rotate around the points on the left
    while (itrll != lower_left_hull.end()) {

        if (switch_to_right == 0) {
            itrll++;
            yi = calculate_ym(*itrll, solution_right2, xm);
            if (yi < ym2) {
                ym2 = yi;
                solution_left2 = *itrll;
                reject = 0;
            }
            else {
                reject++;
                switch_to_right = 1;
                itrll--;
            }
            
        }

        // The inner loop rotate around the points on the right
        if (switch_to_right == 1) {
            while (itrlr != lower_right_hull.end()) {
                itrlr++;
                yi = calculate_ym(solution_left2, *itrlr, xm);
                if (yi < ym2) {
                    ym2 = yi;
                    solution_right2 = *itrlr;
                    reject = 0;
                }
                else {
                    reject++;
                    switch_to_right = 0;
                    itrlr--;
                    break;
                }

                if (reject >= 2) {
                    shouldBreak = true;
                    break;
                }
               
            }
        }

        // Break if get two rejections in a row
        if (reject >= 2 || shouldBreak == true) {
            break;
        }
    }

    // Stitch everything into the overall outer hull
    // A should have “stolen” all the points
    // from B so that its member variables points& hull hold all the individual
    // pointsand the points on the overall hull.B will now be empty.
    upper_left_hull.erase(upper_left_hull.begin(), itrul);
    upper_right_hull.erase(upper_right_hull.begin(), itrur);
    lower_left_hull.erase(lower_left_hull.begin(), itrll);
    lower_right_hull.erase(lower_right_hull.begin(), itrlr);

    hull.erase(hull.begin(), hull.end());
    hull.insert(hull.end(), upper_left_hull.begin(), upper_left_hull.end());
    hull.insert(hull.end(), upper_right_hull.begin(), upper_right_hull.end());
    hull.insert(hull.end(), lower_left_hull.begin(), lower_left_hull.end());
    hull.insert(hull.end(), lower_right_hull.begin(), lower_right_hull.end());

    right.hull.erase(right.hull.begin(), right.hull.end());

    // sort hull
    sort_points(hull);
    ConvexHull hull_points(hull.begin(), hull.end());
    hull_points.generate_hull();
    hull = hull_points.get_hull();
}

double calculate_ym(Point a, Point b, double xm) {
    double k = (b.y - a.y) / (b.x - a.x);
    double c = a.y - k * a.x;
    double ym = k * xm + c;
    return ym;
}
