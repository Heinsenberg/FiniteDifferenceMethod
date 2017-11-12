
#include "stdafx.h"
#include <iostream>
#include "ImplicitFiniteDifference.h"

void show_matrix(vector<double> A) {

	size_t size = int(sqrt(A.size()));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%2.5f ", A[i * size + j]);
		printf("\n");
	}
}

void show_vector(vector<double> A) {

	size_t size = A.size();

	for (int i = 0; i < size; i++) {
		printf("%2.5f ", A[i]);
		//printf("\n");
	}
	int mktSpotArrayIndex = int(0.5*size);

	printf("\n");
	printf("%2.5f ", A[mktSpotArrayIndex]);

}

void main() {

	// Create the instrument parameters
	int callPutFlag = -1;				// +1 call on asset ccy , -1 put on asset ccy
	double strike = 30;					// Strike price
	double expiryInCalendarYears = 1.00; // One year until expiry, need to divide by annualFactor at some point later and have parts of a day

	//Create the market environment
	double spot = 30;
	double discountFactorAsset = exp(0.1);	// discount Factor asset 
	double discountFactorNumeraire = 1.00;  // discount Factor numeraire
	double volatility = 0.3;				// Volatility of the underlying (40%)

	//Create market environment
	MarketEnvironment* MktEnvironment = new MarketEnvironment(spot, discountFactorAsset, discountFactorNumeraire, volatility);

	//Create a European Option 
	EuropeanOption* EuropeanOpt = new EuropeanOption(strike, callPutFlag, expiryInCalendarYears);

	//Create boundary and initial conditions
	BoundaryAndInitialConditions* BndAndInitConditions = new BoundaryAndInitialConditions();
	BndAndInitConditions->setEuropeanOption(EuropeanOpt);
	BndAndInitConditions->setMarketEnvironment(MktEnvironment);

	//Create the Black-Scholes Model 
	BlackScholes1FactorPDE* BS1FactorPDE = new BlackScholes1FactorPDE();
	BS1FactorPDE->setMarketEnvironment(MktEnvironment);

	//Set the range of the vector for the FD grid
	int numberOfSpotLevels = 7; int numberOfTimeSteps = 3;

	//Create FD engine
	ImplicitFiniteDifference* ImplFiniteDifference = new ImplicitFiniteDifference();
	ImplFiniteDifference->setModel(BS1FactorPDE);
	ImplFiniteDifference->setBoundaryAndInitialConditions(BndAndInitConditions);
	ImplFiniteDifference->calculate(numberOfSpotLevels, numberOfTimeSteps);
	
	//Output the result vector
	vector<double> diagonal = ImplFiniteDifference->getFinalOutput();
	show_vector(diagonal);

	int aNumber;
	std::cin >> aNumber;

}
