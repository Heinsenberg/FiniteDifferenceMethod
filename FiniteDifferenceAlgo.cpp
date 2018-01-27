#include <iostream>
#include <map>
#include "FiniteDifferenceEngine.h"

void show_vector(vector<double> A) {

	size_t size = A.size();

	for (int i = 0; i < size; i++) {
		printf("%2.5f ", A[i]);
	}
	int mktSpotArrayIndex = int(0.5*size);

	printf("\n");
	printf("%2.5f ", A[mktSpotArrayIndex]);

}

void main() {
	
	// Create the instrument parameters
	int callPutFlag = -1;				 // +1 call on asset ccy , -1 put on asset ccy
	double strike = 30;					 // Strike price
	double expiryDays = 0.75*365 ;
	double deliveryDays = 0.75 * 365;

	//Create the market environment
	string ccyPair = "EURUSD";
	double fxSpot = 30;                                    // Fx Spot Mid Rate
	vector<double> discountFactorAsset(1000,exp(0.1));	 // discount Factor asset 
	vector<double> discountFactorNumeraire(1000, 1.00);  // discount Factor numeraire
	double volatility = 0.4;							 // Volatility of the underlying (40%)
	double annualFactor = 365.0;						 // AnnualFactor

	// Create the currency pair
	CurrencyPair* CcyPair = new CurrencyPair(ccyPair);
	CcyPair->parse();
	(CcyPair->getError()->getErrorFlag()) ? printf(CcyPair->getError()->getException().what()) : printf("OKAY");

	//Create market environment
	MarketEnvironment* MktEnvironment = new MarketEnvironment(CcyPair,fxSpot, discountFactorAsset, discountFactorNumeraire, volatility);
	MktEnvironment->setAnnualFactor(annualFactor);

	//map of instrument and mkt env? 
	// TreeMap<String,Object> book = new TreeMap<string,Object>();
	// create a 2 node graph : Instrument <-> mktEnv many to 1
	// book = collection of options, indexed by ccy pair
	std:map<string, EuropeanOption> newMap;
	
	//Create a European Option 
	EuropeanOption* EuropeanOpt = new EuropeanOption(CcyPair,strike, callPutFlag, expiryDays, deliveryDays);
	(EuropeanOpt->getError()->getErrorFlag()) ? printf(EuropeanOpt->getError()->getException().what()) : printf("OKAY");
	//newMap[ccyPair] = EuropeanOpt;

	//Create boundary and initial conditions
	BoundaryAndInitialConditions* BndAndInitConditions = new BoundaryAndInitialConditions();
	BndAndInitConditions->setMarketEnvironment(MktEnvironment);
	BndAndInitConditions->setEuropeanOption(EuropeanOpt);
	
	//Create the Black-Scholes Model 
	OneFactorBlackScholes* OneFactorBSModel = new OneFactorBlackScholes();
	OneFactorBSModel->setMarketEnvironment(MktEnvironment);

	//Create FD engine
	ImplicitFiniteDifference* ImplFiniteDifference = new ImplicitFiniteDifference();
	ImplFiniteDifference->setModel(OneFactorBSModel);
	
	FiniteDifferenceEngine* FDE = new FiniteDifferenceEngine();
	FDE->setBoundaryAndInitialConditions(BndAndInitConditions);
	FDE->setImplicitFiniteDifference(ImplFiniteDifference);
	
	//Set the range of the vector for the FD grid
	int numberOfSpotLevels = 7;  int numberOfTimeSteps = 3;
	FDE->calculate(numberOfSpotLevels, numberOfTimeSteps);
	
	//Output the result vector
   (FDE->getError()->getErrorFlag()) ? printf(FDE->getError()->getException().what()) : show_vector(FDE->getFinalResult());

	int aNumber;
	std::cin >> aNumber;

}
