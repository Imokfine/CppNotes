#include <vector>
#include "portfolio.h"

double portfolio_payoff(const std::vector<Trade const*>& trades, const double S_T)
{
     double overall_payoff = 0.0;
     for (auto it = trades.cbegin(); it != trades.cend(); it++) {
         overall_payoff += (*it)->payoff(S_T);
     }

     return overall_payoff;
}

double portfolio_profit(const std::vector<Trade const*>& trades, const double S_T)
{
    double overall_profit = 0.0;
    for (auto it = trades.cbegin(); it != trades.cend(); it++) {
        overall_profit += ((*it)->payoff(S_T) - (*it)->cost);
    }

    return overall_profit;
}

