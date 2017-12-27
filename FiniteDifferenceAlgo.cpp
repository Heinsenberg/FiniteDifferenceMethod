
#include "stdafx.h"
#include <iostream>
#include "FiniteDifferenceEngine.h"

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
	// Create the currency pair
	CurrencyPair* CcyPair = new CurrencyPair("EURUSD");
	CcyPair->parse();
	
	//printf(CcyPair->getErrorMessage().what());
	//printf("\n");

	// Create the instrument parameters
	int callPutFlag = -1;				 // +1 call on asset ccy , -1 put on asset ccy
	double strike = 30;					 // Strike price
	double expiryDays = 0.75*365 ;
	double deliveryDays = 0.75 * 365;

	//Create the market environment
	double spot = 30;
	vector<double> discountFactorAsset(1000,exp(0.1));	 // discount Factor asset 
	vector<double> discountFactorNumeraire(1000, 1.00);  // discount Factor numeraire
	double volatility = 0.4;							 // Volatility of the underlying (40%)

	//Create market environment
	MarketEnvironment* MktEnvironment = new MarketEnvironment(CcyPair,spot, discountFactorAsset, discountFactorNumeraire, volatility);

	//Create a European Option 
	EuropeanOption* EuropeanOpt = new EuropeanOption(CcyPair, strike, callPutFlag, expiryDays, deliveryDays);

	//Create boundary and initial conditions
	BoundaryAndInitialConditions* BndAndInitConditions = new BoundaryAndInitialConditions();
	BndAndInitConditions->setEuropeanOption(EuropeanOpt);
	BndAndInitConditions->setMarketEnvironment(MktEnvironment);

	//Create the Black-Scholes Model 
	OneFactorBlackScholes* OneFactorBSModel = new OneFactorBlackScholes();
	OneFactorBSModel->setMarketEnvironment(MktEnvironment);

	//Set the range of the vector for the FD grid
	int numberOfSpotLevels = 7; int numberOfTimeSteps = 3;

	//Create FD engine
	ImplicitFiniteDifference* ImplFiniteDifference = new ImplicitFiniteDifference();
	ImplFiniteDifference->setModel(OneFactorBSModel);
	
	FiniteDifferenceEngine* FDE = new FiniteDifferenceEngine();
	FDE->setBoundaryAndInitialConditions(BndAndInitConditions);
	FDE->setImplicitFiniteDifference(ImplFiniteDifference);
	FDE->calculate(numberOfSpotLevels, numberOfTimeSteps);

	//Output the result vector
	vector<double> diagonal = FDE->getFinalResult();
	
	(diagonal.size() == 0) ? printf(FDE->getErrorMessage().what()) : show_vector(diagonal);
	
	int aNumber;
	std::cin >> aNumber;

}
