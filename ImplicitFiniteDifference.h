#pragma once
//#include "stdafx.h"
//#include "option.h"
//#include "payoff.h"
#include "BlackScholes1FactorPDE.h"
#include "MarketEnvironment.h"

#ifndef __IMPLICIT_FINITE_DIFFERENCE_H
#define __IMPLICIT_FINITE_DIFFERENCE_H

class ImplicitFiniteDifference{

public:

	void calculate(int _Nminus, int _Nplus);
	
	BlackScholes1FactorPDE* getModel() const { return m_blackScholes1FactorPDE; }
	void setModel(BlackScholes1FactorPDE* _blackScholes1FactorPDE) { m_blackScholes1FactorPDE = _blackScholes1FactorPDE; }

	double* getValues() const { return m_values; }
	double* getB() const { return m_b; }

private:
	BlackScholes1FactorPDE* m_blackScholes1FactorPDE;
	
	void calculateTimeStepSize();
	void calculateSpaceStepize(int _arrayLength);
	void createSpotVector(int _arrayLength);

	double m_dx;
	double m_dt;
	int m_numberOfTimeSteps;
	
	//test output section
	double* m_values;
	double* m_b;
};


#endif