#include "stdafx.h"
#include <math.h>
#include "BlackScholes1FactorPDE.h"

// dS(t)/S(t) = mu*t + volatility*dW(0,1); => assume x:= ln(S(t)/S(t+1)) 
// which gives a single variable diffusion equartion dx/dt = d^2x/dt^2

BlackScholes1FactorPDE::BlackScholes1FactorPDE(){}

// Diffusion coefficient
double BlackScholes1FactorPDE::diffCoeff(double t, double x) const {
	double vol = getMarketEnvironment()->getVolatility(); 
	return 0.5*vol*vol*x*x;  // \frac{1}{2} \sigma^2 S^2
}

// Convection coefficient
double BlackScholes1FactorPDE::driftCoeff(double t, double x) const {
	double drift = std::log(getMarketEnvironment()->getDiscountFactorAsset()) - std::log(getMarketEnvironment()->getDiscountFactorNumeraire());
	return drift*x;  // rS
}


//For a vanilla call option
// Left boundary-condition 
double BlackScholes1FactorPDE::boundaryLeft(double t, double x) const {
	return 0.0;  // Specifically for a CALL option
}

// Right boundary-condition 
double BlackScholes1FactorPDE::boundaryRight(double t, double x) const {
	// This is via Put-Call Parity and works for a call option

	return x - getVanillaOption()->getStrike()*getMarketEnvironment()->getDiscountFactorAsset();
}

// Initial condition 
double BlackScholes1FactorPDE::initialCondition(double x) const {
	
	return getVanillaOption()->getPayOff()->operator()(x);
}

