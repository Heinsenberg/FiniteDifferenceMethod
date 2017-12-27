#ifndef __CURRENCYPAIR_H
#define __CURRENCYPAIR_H

#include "ErrorHandler.h"

class CurrencyPair {

public:
	CurrencyPair(string _currencyPair);
	~CurrencyPair();

	void parse();

	string getCurrencyPair() { return m_currencyPair; };
	string getLHSCurrency() { return m_LHSCurrency; };
	string getRHSCurrency() { return m_RHSCurrency; };

	ErrorHandler* getError() { return m_error; };
	
private:

	void splitCurrencyPair();

	string m_inputCurrencyPair;
	string m_currencyPair;
	string m_LHSCurrency;
	string m_RHSCurrency;

	ErrorHandler* m_error;
};

#endif

