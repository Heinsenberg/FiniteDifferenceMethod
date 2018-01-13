#include "Instrument.h"


Instrument::Instrument(){
}


Instrument::~Instrument(){
}

PayOff * Instrument::operator()(const PayOff & _payOff){
	return m_payOff;
}

EuropeanOption::EuropeanOption(const double& _strike, const int& _callPutFlag, double& _expiryDays, double& _deliveryDays){
	
	m_error = new ErrorHandler();

	try {
		(_strike < 0) ? throw runtime_error("Strike must be greater than 0") : m_strike = _strike;

	}
	catch (runtime_error& e) {
		m_error->setException(e);
		m_error->setErrorFlag(true);
		return;
	}

	try {
		(_expiryDays  < 0) ? throw runtime_error("Expiry days must be greater than 0") : m_expiryDays = _expiryDays;

	}
	catch (runtime_error& e) {
		m_error->setException(e);
		m_error->setErrorFlag(true);
		return;
	}
	
	try {
		(_deliveryDays < 0) ? throw runtime_error("Delivery days must be greater than 0") : m_deliveryDays = _deliveryDays;

	}
	catch (runtime_error& e) {
		m_error->setException(e);
		m_error->setErrorFlag(true);
		return;
	}

	try {
		(abs(_callPutFlag)  != 1) ? throw runtime_error("Option type must be +1 (call on asset ccy) or -1 (put on asset ccy)") : m_callPutFlag = _callPutFlag;

	}
	catch (runtime_error& e) {
		m_error->setException(e);
		m_error->setErrorFlag(true);
		return;
	}

	m_payOff = new PayOffVanilla(_strike, _callPutFlag);
}

PayOff * EuropeanOption::operator()(const PayOff & _payOff) const{
	return m_payOff;
}
