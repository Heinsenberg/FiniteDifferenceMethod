
#ifndef __INSTRUMENT_H
#define __INSTRUMENT_H

#include "payoff.h"
#include "CurrencyPair.h"

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
	EuropeanOption(CurrencyPair* _currencyPair, const double& _strike, const int& _callPutFlag, double& _expiryInDays, double& _deliveryDays);
	virtual ~EuropeanOption() {};

	// Virtual function is now over-ridden (not pure-virtual anymore)
	virtual PayOff* operator() (const PayOff& _payOff) const;
	
	double getStrike() const { return m_strike; };
	double getExpiryDays() const { return m_expiryDays; };
	double getDeliveryDays() const { return m_deliveryDays; };
	int getCallPutFlag() const { return m_callPutFlag; };
	CurrencyPair* getCurrencyPair() const { return m_currencyPair; };
	PayOff* getPayOff() const { return m_payOff; };
	ErrorHandler* getError() const { return m_error; };

private:
	double m_strike;
	double m_expiryDays;
	double m_deliveryDays;
	int m_callPutFlag;
	CurrencyPair* m_currencyPair;
	ErrorHandler* m_error;

};

#endif