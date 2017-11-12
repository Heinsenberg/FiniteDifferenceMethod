// ConsoleApplication1.cpp : Defines the entry point for the console application.

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
}

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

	//Create an Instrument 
	EuropeanOption* EuropeanOpt = new EuropeanOption(strike, callPutFlag, expiryInCalendarDays);
	PayOffVanilla* EuroPayOff = new PayOffVanilla(strike,callPutFlag);

	//Create boundary and initial conditions
	BoundaryAndInitialConditions* BndAndInitConditions = new BoundaryAndInitialConditions();
	BndAndInitConditions->setEuropeanOption(EuropeanOpt);

	//Create the Black-Scholes equation params
	BlackScholes1FactorPDE* BS1FactorPDE = new BlackScholes1FactorPDE();
	BS1FactorPDE->setMarketEnvironment(MktEnvironment);
		
	int Nminus = -3; int Nplus = 3;
	
	//Create FD engine
	ImplicitFiniteDifference* ImplFiniteDifference = new ImplicitFiniteDifference();
	ImplFiniteDifference->setModel(BS1FactorPDE);
	ImplFiniteDifference->calculate(Nminus, Nplus);
	
	vector<double> diagonal = ImplFiniteDifference->getFinalOutput();
	show_vector(diagonal);
	
	printf("\n");

	diagonal = ImplFiniteDifference->getInitialCondition();
	show_vector(diagonal);

	printf("\n");

	//diagonal = ImplFiniteDifference->getDiagonal();
	//show_vector(diagonal);

	int aNumber;
	std::cin >> aNumber;

	//Test the LU class

	/*
	vector<double> initMatrix = { 2.0,1.0,1.0,3.0,2.0,
	1.0,2.0,2.0,1.0,1.0,
	1.0,2.0,9.0,1.0,5.0,
	3.0,1.0,1.0,7.0,1.0,
	2.0,1.0,5.0,1.0,8.0};


	Cholesky* CholeskyMethod = new Cholesky(initMatrix);
	vector<double> val2 = CholeskyMethod->getLU();
	*/

	// Create some output & Input	
	//vector<double> val = ImplFiniteDifference->getInitialCondition();

	//show_matrix(val2);

	//vector<double> initMatrix = { 25.0, 15.0, -5.0,
	//						15.0, 18.0,  0.0,
	//						-5.0,  0.0, 11.0 };

	//vector<double> initMatrix = { 18, 22,  54,  42,
	//	22, 70,  86,  62,
	//	54, 86, 174, 134,
	//	42, 62, 134, 106 };

}