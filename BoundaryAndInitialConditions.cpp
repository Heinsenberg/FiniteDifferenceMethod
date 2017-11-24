#include "stdafx.h"
#include "BoundaryAndInitialConditions.h"


BoundaryAndInitialConditions::BoundaryAndInitialConditions() {
}


BoundaryAndInitialConditions::~BoundaryAndInitialConditions() {
}

double BoundaryAndInitialConditions::boundaryLeft(double t, double x) const {
	double returnValue = 0.0;

	if (getEuropeanOption()->getCallPutFlag() == 1) {
	
		returnValue = getMarketEnvironment()->getFXSpot();

	}

	return returnValue;
}

double BoundaryAndInitialConditions::boundaryRight(double t, double x) const {
		double returnValue = 0.0;

		if (getEuropeanOption()->getCallPutFlag() == -1) {
			// something like strike*exp(-r*tau)
			double assetDepoRate = log(getMarketEnvironment()->getDiscountFactorAsset());
			double discountRate = exp(-assetDepoRate*t);

			returnValue = getEuropeanOption()->getStrike()*discountRate;
		}
		
		return returnValue;
}

double BoundaryAndInitialConditions::initialCondition(double _x) const {
	return getEuropeanOption()->getPayOff()->operator()(_x);
}
