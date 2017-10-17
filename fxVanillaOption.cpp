#include "stdafx.h"
#include "fxVanillaOption.h"

#ifndef __FX_VANILLA_OPTION_CPP
#define __FX_VANILLA_OPTION_CPP

FXVanillaOption::FXVanillaOption() {}

FXVanillaOption::FXVanillaOption(int _callPutFlag, double _strike,double _expiryInYears) {

	m_strike = _strike;
	m_expiryInYears = _expiryInYears;
	m_payOff = new PayOffVanilla(m_strike, _callPutFlag);

}

#endif