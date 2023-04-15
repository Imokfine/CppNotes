/**
 * @file grid.cc
 * @brief Implemention of grid.h file
 * @author Xueni Fu
 * @version 1.0
 * @date 2023-04-13
 */

#include "grid.h"

// Overloading constructor
Grid::Grid(int x, int y, int z) : width{ x }, height{ y }, orig_population{ z } {
	data.resize(static_cast<std::vector<int>::size_type>(width));
	for (long unsigned int i = 0; i < static_cast<std::vector<int>::size_type>(width); i++) {
		data[i].resize(static_cast<std::vector<int>::size_type>(height));
	}
}

// Simply clear the list at each site in between each turn.
void Grid::reset_grid() {
	for (long unsigned int i = 0; i < static_cast<std::vector<int>::size_type>(width); i++) {
		for (long unsigned int j = 0; j < static_cast<std::vector<int>::size_type>(height); j++) {
			data[i][j].clear();
		}
	}
}

// Iterates through the population and checks the current location of each.
// It update the corresponding Grid data container so that it holds the index of the Person for the corresponding coordinates.
// param pop    vector of Person
void Grid::update_grid_counts(std::vector<Person>& pop) {
	reset_grid();

	currently_infected = 0;

	for (long unsigned int i = 0; i < pop.size(); i++) {
		data[static_cast<std::vector<int>::size_type>(pop[i].current_location.x)][static_cast<std::vector<int>::size_type>(pop[i].current_location.y)].push_back(i);
		if (pop[i].infected)
			currently_infected++;
	}

	
}

// Print the grid to screen with the counts of the number of Persons at each site.
// param os    Reference to output stream
// param in     Reference to Grid which we want to print.
// return      Reference to output stream
std::ostream& operator<< (std::ostream& os, Grid& in) {
	for (long unsigned int i = 0; i < static_cast<std::vector<int>::size_type>(in.width); i++) {
		for (long unsigned int j = 0; j < static_cast<std::vector<int>::size_type>(in.height); j++) {
			os << " " << in.data[i][j].size() << " ";
		}
		os << "\n";
	}
	return os;
}

// Updates the health status of each Person
// param pop    vector of Person
void Grid::update_health_status(std::vector<Person>& pop) {
	for (auto it = pop.begin(); it != pop.end();) { // end() points to a memory location that is one past the last element of the vector
		if (it->infected) {

			it->days_to_recovery--;
			it->days_to_death--;

			if (it->days_to_recovery == 0) {
				it->immune = true;
				it->infected = false;
				currently_infected--;
				recovered++;
				it++;
			}
			else if (it->days_to_death <= 0) {
				pop.erase(it); // this return the iterator of next element, so do not use it++ here
				currently_infected--;
				dead++;
			}
			else {
				it++;
			}
			
		}
		else {
			it++;
		}
		
	}
}

// Update the configuration after all of the moves between grid sites have been made.
// param pop    vector of Person
void Grid::update_configuration(std::vector<Person>& pop) {
	// newly infected Person cannot immediately infect another in the same turn

	update_grid_counts(pop);

	std::uniform_real_distribution<> infdis(0, 1);

	std::vector<long unsigned int> newly_inf(pop.size());
	std::fill(newly_inf.begin(), newly_inf.end(), 0); // 0 means is not newly infected people, 1 means is newly infected

	for (long unsigned int i = 0; i < pop.size(); i++) {

		// if is infected
		if (pop[i].infected) {

			// if is not newly infected
			if (newly_inf[i] == 0) {
				// number of people on the same grid
				long unsigned int num_people = data[static_cast<std::vector<int>::size_type>(pop[i].current_location.x)][static_cast<std::vector<int>::size_type>(pop[i].current_location.y)].size(); 

				if (num_people >= 2) {

					// infect other people on the grid with the probability
					for (long unsigned int j = 0; j < num_people; j++) {
						long unsigned int idx_people = static_cast<long unsigned int>(data[static_cast<std::vector<int>::size_type>(pop[i].current_location.x)][static_cast<std::vector<int>::size_type>(pop[i].current_location.y)][j]);

						if (!pop[idx_people].infected && !pop[idx_people].immune && newly_inf[idx_people] == 0 &&
							infdis(gen) <= pop[idx_people].params->transmission_prob) {
							infect_on_grid(pop[idx_people]);
							newly_inf[idx_people] = 1;
						}
					}
				}
			}
		}
	}

	update_health_status(pop);

}

// Print the statistics at each turn to a file. When the function is called, it should append the appropriate stats to the end of the input file.
// param in       filename
// param i        turn/iteration number
void Grid::print_stats(std::string in, int i) {
	std::ofstream file;
	file.open(in, std::ios_base::app);   // Append instead of overwrite

	if (!file) {
		std::cerr << "Error: cannot open file" << std::endl;
	}

	if (file.is_open()) {
		// Format | iteration number | population | currently infected | recovered | dead | didn't catch |
		file <<  i << ","
			 << orig_population << "," 
			 << currently_infected <<"," 
			 << recovered << ","
			 << dead << ","
			 << orig_population - currently_infected - recovered - dead << std::endl;
	}

}
