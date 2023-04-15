/**
 * @file person.h
 * @brief Header file containing class defintion for Person class
 * @author Xueni Fu modified from R. Morrin
 * @version 1.0
 * @date 2023-04-13
 */
#ifndef PERSON_H_UEFXG10N
#define PERSON_H_UEFXG10N

#include <memory>
#include "assignment4.h"

/**
 * @brief Class to hold data related to a person in the model
 */
class Person
{
public:
    Person (Point s, std::shared_ptr<Params> p);

    friend std::ostream& operator<<(std::ostream & os, const Person & p);
    void propose_move(); 		

private:
    Point current_location;
    Point original_location;
    std::shared_ptr<Params> params;

    friend class Grid;
    void infect();
    int days_to_recovery;
    int days_to_death;
    bool infected = false;
    bool immune = false;
    

};

#endif /* end of include guard: PERSON_H_UEFXG10N */
