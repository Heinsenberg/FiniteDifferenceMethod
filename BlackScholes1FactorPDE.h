#ifndef __BLACKSCHOLES1FACTORPDE_H
#define __BLACKSCHOLES1FACTORPDE_H
 
#include "stdafx.h"
#include "MarketEnvironment.h"

class BlackScholes1FactorPDE
{
public:
	BlackScholes1FactorPDE();
	
	double diffCoeff(double t, double x) const;
	double driftCoeff(double t, double x) const;
		
	MarketEnvironment* getMarketEnvironment() const { return m_marketEnvironment; }
	void setMarketEnvironment(MarketEnvironment* _marketEnvironment) { m_marketEnvironment = _marketEnvironment; }

private:
	MarketEnvironment* m_marketEnvironment;
	
};

#endif

