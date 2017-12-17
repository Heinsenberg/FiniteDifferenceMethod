#include "stdafx.h"
#include "BoundaryAndInitialConditions.h"

BoundaryAndInitialConditions::BoundaryAndInitialConditions() {
}

BoundaryAndInitialConditions::~BoundaryAndInitialConditions() {
}

double BoundaryAndInitialConditions::boundaryLeft(double _t, double _x) const {

	double returnValue;

	(getEuropeanOption()->getCallPutFlag() == 1) ? returnValue = getMarketEnvironment()->getFXSpot() : returnValue = 0.0;

	return returnValue;
}

double BoundaryAndInitialConditions::boundaryRight(double _t, double _x) const {
			double returnValue;

			int expiryDays = (int)getEuropeanOption()->getExpiryInDays();
			double discountFactorAsset = getMarketEnvironment()->getDiscountFactorAsset()[expiryDays];
			double timeInYears = _t / getMarketEnvironment()->getAnnualFactor();
			
			(getEuropeanOption()->getCallPutFlag() == -1) ? returnValue = getEuropeanOption()->getStrike()*pow(discountFactorAsset, timeInYears) : returnValue = 0.0;
		
		return returnValue;
}

double BoundaryAndInitialConditions::initialCondition(double _x) const {
	return getEuropeanOption()->getPayOff()->operator()(_x);
}
