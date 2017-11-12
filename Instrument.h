#pragma once
#include "payoff.h"

class Instrument
{
public:

	Instrument();
	~Instrument();

	// Overloaded() operator, turns the PayOff into an abstract functor
		virtual PayOff* operator() (const PayOff& _payOff) ;

protected:
	PayOff* m_payOff;

};

class EuropeanOption : public Instrument {

public:
	EuropeanOption(const double& _strike, const int& _callPutFlag, double& _expiryInDays);
	virtual ~EuropeanOption() {};

	// Virtual function is now over-ridden (not pure-virtual anymore)
	virtual PayOff* operator() (const PayOff& _payOff) const;
	double getStrike() const { return m_strike; };
	double getExpiryInDays() const { return m_expiryInDays; };
	int getCallPutFlag() const { return m_callPutFlag; };
	PayOff* getPayOff() const { return m_payOff; };

private:
	double m_strike;
	double m_expiryInDays;
	int m_callPutFlag;
	
};

