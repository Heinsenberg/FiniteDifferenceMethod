#include "stdafx.h"
#include "Instrument.h"


Instrument::Instrument(){
}


Instrument::~Instrument(){
}

PayOff * Instrument::operator()(const PayOff & _payOff){
	return m_payOff;
}

EuropeanOption::EuropeanOption(CurrencyPair* _ccyPair, const double& _strike, const int& _callPutFlag, double& _expiryInDays){
	m_strike = _strike;
	m_expiryInDays = _expiryInDays;
	m_callPutFlag = _callPutFlag;
	m_currencyPair = _ccyPair;
	m_payOff = new PayOffVanilla(_strike, _callPutFlag);
}

PayOff * EuropeanOption::operator()(const PayOff & _payOff) const{
	return m_payOff;
}
