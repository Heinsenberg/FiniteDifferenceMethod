#include "payoff.h"

#ifndef __FX_VANILLA_OPTION_H
#define __FX_VANILLA_OPTION_H

class FXVanillaOption {
public:

	FXVanillaOption();

	FXVanillaOption(int _callPutFlag, double _strike,double _expiryInYears);

	double getStrike() { return m_strike; }
	double getExpiryInYears() { return m_expiryInYears; }
	PayOff* getPayOff() const { return m_payOff; };


protected:
	double m_strike;
	double m_expiryInYears;
	PayOff* m_payOff;
	
};

#endif
