// ConsoleApplication1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>

#include "payoff.h"
#include "fxVanillaOption.h"
#include "MarketEnvironment.h"
#include "ImplicitFiniteDifference.h"

void main() {
	// Create the instrument parameters
	int callPutFlag = 1; // +1 call on asset ccy , -1 put on asset ccy
	double strike = 100;  // Strike price
	double expiryInCalendarDays = 30.00;    // One month until expiry
	
	//Create the market environment
	double spot = 100;
	double discountFactorAsset = 1.00;   // discount Factor asset 
	double discountFactorNumeraire = 1.00;   // discount Factor numeraire
	double volatility = 0.2;    // Volatility of the underlying (20%)
	
	//Create market environment
	MarketEnvironment* MktEnvironment = new MarketEnvironment(spot,discountFactorAsset,discountFactorNumeraire,volatility);

	//Create a Vanilla Option
	FXVanillaOption* VanillaCallOption = new FXVanillaOption(callPutFlag,strike,expiryInCalendarDays);
	
	//Create the Black-Scholes equation params
	BlackScholes1FactorPDE* BS1FactorPDE = new BlackScholes1FactorPDE();
	BS1FactorPDE->setMarketEnvironment(MktEnvironment);
	BS1FactorPDE->setVanillaOption(VanillaCallOption);

	int Nminus = -25; int Nplus = 25;
	int arrayLength = Nplus - Nminus;

	//Create FD engine
	ImplicitFiniteDifference* ImplFiniteDifference = new ImplicitFiniteDifference();
	ImplFiniteDifference->setModel(BS1FactorPDE);
	ImplFiniteDifference->calculate(Nminus, Nplus);

	// Create some output & Input
	
	double* val = ImplFiniteDifference->getValues();
	double* b = ImplFiniteDifference->getB();

	for (int i = 1; i <= arrayLength; i++) {
		std::cout << i << " " << val[i] << " " << b[i] << std::endl;
	}

	int aNumber;
	std::cin >> aNumber;

}