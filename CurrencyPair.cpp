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
		(m_inputCurrencyPair.length() < 6) ? throw invalid_argument("String submitted isnt long enough to create 2 x currency ISO substrings, try EURUSD or EUR/USD") : splitCurrencyPair();

	}
	catch (invalid_argument& e) {
		m_errorMessage = e;
	}
}

void CurrencyPair::splitCurrencyPair() {
	m_LHSCurrency = m_inputCurrencyPair.substr(0, 3);
	m_RHSCurrency = m_inputCurrencyPair.substr(m_inputCurrencyPair.length()-3, 3);
	m_currencyPair = m_LHSCurrency + m_RHSCurrency;
}
