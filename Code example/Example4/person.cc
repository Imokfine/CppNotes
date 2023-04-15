/**
 * @file person.cc
 * @brief Implemention of person.h file
 * @author Xueni Fu
 * @version 1.0
 * @date 2023-04-13
 */

#include <iostream>
#include <memory>
#include "person.h"
#include "assignment4.h"

// Overloading constructor
Person::Person(Point s, std::shared_ptr<Params> p) : current_location{ s }, original_location{s}, params{p} {
    // std::cout << "Constructing Point " << s << "\n";
}

// This operator should output the current location Point from p.
// param os    Reference to output stream
// param p     Reference to Person which we want to print their current location.
// return      Reference to output stream
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.current_location;
    return os;
}


// This function randomly propose a move for each square and then accept or reject that move with probability
void Person::propose_move() {

    int xleft{current_location.x}, xright{ current_location.x }, yup{ current_location.y }, ydown{ current_location.y };
    int new_x, new_y; // the new coordinate after moving
    double prob;

    std::cout << " xleft = %d " << xleft << "xright = %d " << xright << " yup = %d " << yup << " ydown = %d " << ydown << "\n";


    double r1; // r1 = sqrt((old_x - home_x)^2 + (old_y - home_y)^2)
    double r2; // r2 = sqrt((new_x - home_x)^2 + (new_y - home_y)^2)
    double k = params->spring_constant; // set k to desired value

    // Set the move grid
    if (current_location.x > 0)
        xleft--;
    if (current_location.x < params->xdim - 1)
        xright++;
    if (current_location.y > 0)
        yup--;
    if (current_location.y < params->ydim - 1)
        ydown++;

    // Possible location after moving
    std::uniform_int_distribution<> xdis{ xleft, xright };
    std::uniform_int_distribution<> ydis{ yup, ydown };

    new_x = xdis(gen);
    new_y = ydis(gen);
    
    int old_vec_x = current_location.x - original_location.x;
    int old_vec_y = current_location.y - original_location.y;
    int new_vec_x = new_x - original_location.x;
    int new_vec_y = new_y - original_location.y;

    // Accept or reject
    r1 = std::sqrt(pow(old_vec_x, 2) + pow(old_vec_y, 2));
    r2 = std::sqrt(pow(new_vec_x, 2) + pow(new_vec_y, 2));

    prob = exp(-k * (pow(r2, 2) - pow(r1, 2)));
    std::uniform_real_distribution<> p_accept(0, 1);

    // If r2 < r1, we will always accept the move. If r2 > r1 then we will accept the move with probability
    if (r2 <= r1) { // I also put r2 = r1 here
        current_location.x = new_x;
        current_location.y = new_y;
    }
    else if (p_accept(gen) < prob) {
        current_location.x = new_x;
        current_location.y = new_y;
    }

}

// This function should set the member bool infected to true for the Person.
// It should also randomly assign the days_to_death variable for that person, 
// and finally copy the time_to_recovery from the Params class to the member variable days_to_recovery.
void Person::infect() {
    infected = true;
    std::uniform_int_distribution<> death_dis(0, 365);
    days_to_death = death_dis(gen);
    days_to_recovery = params->time_to_recovery;
}
