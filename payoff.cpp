#include "payoff.h"
#include <algorithm>

PayOff::PayOff() {}

// Constructor with single strike parameter and CALLPUT flag
PayOffVanilla::PayOffVanilla(const double& _strike, const int& _callPutFlag) { m_strike = _strike; m_callPutFlag = _callPutFlag; }

// Over-ridden operator() method, which turns PayOffVanilla into a functor
double PayOffVanilla::operator() (const double& spot) const {
	return std::max(m_callPutFlag*(spot - m_strike), 0.0); // Standard Vanilla pay-off

}
