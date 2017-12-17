#include "stdafx.h"
#include <stdexcept>
#include "CurrencyPair.h"

CurrencyPair::CurrencyPair(string _currencyPair) {
	m_inputCurrencyPair = _currencyPair;

}

CurrencyPair::~CurrencyPair() {
	
}

void CurrencyPair::parse() {
	try {
		(m_inputCurrencyPair.length() != 6) ? throw runtime_error("You inputted: '" + m_inputCurrencyPair + "'  this string isnt formed of create 2 x currency strings, try the format like EURUSD, GBPUSD, USDJPY etc") : splitCurrencyPair();

	}
	catch (runtime_error& e) {
		m_errorMessage = e;
	}
}

void CurrencyPair::splitCurrencyPair() {
	m_LHSCurrency = m_inputCurrencyPair.substr(0, 3);
	m_RHSCurrency = m_inputCurrencyPair.substr(m_inputCurrencyPair.length()-3, 3);
	m_currencyPair = m_LHSCurrency + m_RHSCurrency;
}
