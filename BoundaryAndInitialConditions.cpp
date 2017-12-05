#include "stdafx.h"
#include "BoundaryAndInitialConditions.h"

BoundaryAndInitialConditions::BoundaryAndInitialConditions() {
}

BoundaryAndInitialConditions::~BoundaryAndInitialConditions() {
}

double BoundaryAndInitialConditions::boundaryLeft(double t, double x) const {

	double returnValue;

	(getEuropeanOption()->getCallPutFlag() == 1) ? returnValue = getMarketEnvironment()->getFXSpot() : returnValue = 0.0;

	return returnValue;
}

double BoundaryAndInitialConditions::boundaryRight(double t, double x) const {
		double returnValue = 0.0;

		if (getEuropeanOption()->getCallPutFlag() == -1) {
			// something like strike*exp(-r*tau) DF(t,T) 
			// DF(t,T) = exp(-r*(T-t)) = DF(0,T) / DF(0,t) = DF[T] / DF[t];
			// (getEuropeanOption()->getCallPutFlag() == -1) ? returnValue = getMarketEnvironment()->getDiscountFactorAsset()[expiryDays]/getMarketEnvironment()->getDiscountFactorAsset()[t] : returnValue = 0.0;
			int expiryDays = (int) getEuropeanOption()->getExpiryInDays();

			double discountFactorAsset = getMarketEnvironment()->getDiscountFactorAsset()[expiryDays];
			double assetDepoRate = log(discountFactorAsset);
			double discountRate = exp(-assetDepoRate*t);

			returnValue = getEuropeanOption()->getStrike();
		}
		
		return returnValue;
}

double BoundaryAndInitialConditions::initialCondition(double _x) const {
	return getEuropeanOption()->getPayOff()->operator()(_x);
}
