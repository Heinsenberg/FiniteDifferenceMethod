#ifndef __BOUNDARY_AND_INITIAL_CONDITIONS_H
#define __BOUNDARY_AND_INITIAL_CONDITIONS_H

#include "Instrument.h"
#include "MarketEnvironment.h"

class BoundaryAndInitialConditions
{
public:
	BoundaryAndInitialConditions();
	~BoundaryAndInitialConditions();

	double boundaryLeft(double t, double x) const;
	double boundaryRight(double t, double x) const;
	double initialCondition(double _x) const;

	MarketEnvironment* getMarketEnvironment() const { return m_marketEnvironment; }
	void setMarketEnvironment(MarketEnvironment* _marketEnvironment) { m_marketEnvironment = _marketEnvironment; }

	EuropeanOption* getEuropeanOption() const { return m_europeanOption; }
	void setEuropeanOption(EuropeanOption* _europeanOption) { m_europeanOption = _europeanOption; }
	
private:
	MarketEnvironment* m_marketEnvironment;
	EuropeanOption* m_europeanOption;

};

#endif
