#include "stdafx.h"
#include "math.h"
#include "BlackScholes1FactorPDE.h"

BlackScholes1FactorPDE::BlackScholes1FactorPDE(){}

// Diffusion coefficient
double BlackScholes1FactorPDE::diffCoeff(double t, double x) const {
	double vol = getMarketEnvironment()->getVolatility(); 
	return 0.5*vol*vol*x*x;  
}

// Convection coefficient
double BlackScholes1FactorPDE::driftCoeff(double t, double x) const {
	
	double drift = log(getMarketEnvironment()->getDiscountFactorAsset()[0]) - log(getMarketEnvironment()->getDiscountFactorNumeraire()[0]);
	return drift*x;  
}