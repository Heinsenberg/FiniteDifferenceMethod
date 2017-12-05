#ifndef __CURRENCYPAIR_H
#define __CURRENCYPAIR_H

#include <string>
using namespace std;

class CurrencyPair {

public:
	CurrencyPair(string _currencyPair);
	~CurrencyPair();

	void parse();

	string getCurrencyPair() { return m_currencyPair; };
	string getLHSCurrency() { return m_LHSCurrency; };
	string getRHSCurrency() { return m_RHSCurrency; };
	exception getErrorMessage() { return m_errorMessage; };

	
private:

	void splitCurrencyPair();

	string m_inputCurrencyPair;
	string m_currencyPair;
	string m_LHSCurrency;
	string m_RHSCurrency;

	exception m_errorMessage;
};

#endif

