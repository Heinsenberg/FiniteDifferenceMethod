#pragma once
#include "payoff.h"
#include "fxVanillaOption.h"
#include "MarketEnvironment.h"

class BlackScholes1FactorPDE
{
public:
	BlackScholes1FactorPDE();
	
	double diffCoeff(double t, double x) const;
	double driftCoeff(double t, double x) const;
	
	double boundaryLeft(double t, double x) const;
	double boundaryRight(double t, double x) const;
	double initialCondition(double x) const;

	MarketEnvironment* getMarketEnvironment() const { return m_marketEnvironment; }
	void setMarketEnvironment(MarketEnvironment* _marketEnvironment) { m_marketEnvironment = _marketEnvironment; }

	FXVanillaOption* getVanillaOption() const { return m_vanillaOption; }
	void setVanillaOption(FXVanillaOption* _vanillaOption) { m_vanillaOption = _vanillaOption; }

private:
	MarketEnvironment* m_marketEnvironment;
	FXVanillaOption* m_vanillaOption;

};

