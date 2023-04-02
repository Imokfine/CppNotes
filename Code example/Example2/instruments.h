#ifndef INSTRUMENTS_H_VK2TICXL
#define INSTRUMENTS_H_VK2TICXL
#include <vector>
#include <iostream>

/**
 * @brief Abstract Base Class Trade
 * 	This class represents the concept of a trade i.e. something we buy, or a contract that we enter into
 */
class Trade
{
public:
        // TODO:
        // (1) Define copy and move constructors as default
        // (2) Delete assignment operators

	/**
	 * @brief Default construtor for Trade class
	 * 	This sets the value of cost equal to zero
	 */
	Trade() : cost{0}{
		std::cout << "Trade (base class) Constructor (Default)\n";
	}

	/**
	 * @brief Constructor for Trade class
	 *
	 * @param[in] cost This parameter is the price you paid to purchase, or enter the trade
	 */
	Trade (const double cost) : cost {cost} {
		std::cout << "Trade (base class) Constructor (overloaded)\n";
	}

	Trade(const Trade&) = default; // Copy constructor
	Trade(Trade&&) = default; // Move constructor

	// Delete assignment operators
	Trade& operator=(const Trade&) = delete;
	Trade& operator=(Trade&&) = delete;


	/**
	 * @brief Destructor for Trade
	 */
	virtual ~Trade (){
		std::cout << "Trade (base class) Destructor\n";
	}

	// TODO:
	// (3) declare payoff as a pure virtual constant member function
	// (4) Grant access to private member of this class to any non-member functions that need it

	virtual double payoff(double ST) const = 0; // Pure virtual constant payoff function

	// Declare friend functions for which needs private member cost
	friend class Call;
	friend class Put;
	friend double portfolio_profit(const std::vector<Trade const*>& trades, const double S_T);

private:
	const double cost;	///< Holds the premium, or cost paid to enter the trade
};

/**
 * @brief Class to represent a forward trade
 */

class Forward : public Trade {
public:
	Forward(double fp) : forward_price{fp}{
		std::cout << "Constructor for Forward with forward price " << forward_price << "\n";
	}

	Forward(const Forward&) = default; // Copy constructor
	Forward(Forward&&) = default; // Move constructor

	Forward& operator=(const Forward&) = delete;
	Forward& operator=(Forward&&) = delete;

	Forward() = delete; // Delete default constructor
	~Forward() {
		std::cout << "Deleting Forward with forward price " << forward_price << "\n";
	}

	double payoff(double ST) const override final{
		return ST - forward_price;
	}

private:
	const double forward_price;
};

/**
 * @brief Class to represent a Call Option
 */

class Call : public Trade {
public:
	Call(double cost, double k) : Trade{cost},strike{k}{
		std::cout << "Creating Call with strike " << strike << ". Premium paid " << cost << "\n";
	}

	Call(const Call&) = default; // Copy constructor
	Call(Call&&) = default; // Move constructor

	Call& operator=(const Call&) = delete;
	Call& operator=(Call&&) = delete;

	Call() = delete; // Delete default constructor
	~Call() {
		std::cout << "Destorying Call with strike " << strike << "\n";
	}

	double payoff(double ST) const override final {
		return std::max(ST - strike, 0.0);
	}

private:
	const double strike;
};

/**
 * @brief Class to represent a Put Option
 */

class Put : public Trade {
public:
	Put(double cost, double k) : Trade{cost}, strike{k} {
		std::cout << "Creating Put with strike " << strike << ". Premium paid " << cost << "\n";
	}

	Put(const Put&) = default; // Copy constructor
	Put(Put&&) = default; // Move constructor

	Put& operator=(const Put&) = delete;
	Put& operator=(Put&&) = delete;

	Put() = delete; // Delete default constructor
	~Put() {
		std::cout << "Destorying Put with strike " << strike << "\n";
	}

	double payoff(double ST) const override final {
		return std::max(strike - ST, 0.0);
	}

private:
	const double strike;
};

#endif /* end of include guard: INSTRUMENTS_H_VK2TICXL */

