
#include "stdafx.h"
#include "ImplicitFiniteDifference.h"


void ImplicitFiniteDifference::calculate(int Nminus, int Nplus) {

	int arrayLength = abs(Nminus) + abs(Nplus);

	calculateTimeStepSize();
	calculateSpaceStepize(arrayLength);
	createSpotVector(arrayLength);

	double alpha = m_dt / (m_dx*m_dx);
	double tau = 0.0;

	m_b = new double[arrayLength];
 
	//ThomasAlgorithmLU
	
	for (int i = 1; i <= m_numberOfTimeSteps; i++){

		tau = i*m_dt;

		for (int j = 1; j <= arrayLength; j++){
			m_b[j] = m_values[j];
		}

		m_values[1] = m_blackScholes1FactorPDE->boundaryLeft(tau, m_dx);
		m_values[arrayLength] = m_blackScholes1FactorPDE->boundaryRight(tau, arrayLength*m_dx);

		m_b[2] += alpha*m_values[1];
		m_b[arrayLength-1] += alpha*m_values[arrayLength];

		//ThomasAlgorithmSolve
	}
	
	
}

void ImplicitFiniteDifference::calculateTimeStepSize()
{
	double expiryInDays = m_blackScholes1FactorPDE->getVanillaOption()->getExpiryInYears();
	m_numberOfTimeSteps = int(expiryInDays);
	m_dt = 1;
	
}

void ImplicitFiniteDifference::calculateSpaceStepize(int arrayLength){
	double spot = m_blackScholes1FactorPDE->getMarketEnvironment()->getFXSpot();
	m_dx = spot/arrayLength;
}

void ImplicitFiniteDifference::createSpotVector(int arrayLength)
{
	double minSpotValue = m_blackScholes1FactorPDE->getMarketEnvironment()->getFXSpot()+m_dx*(int(0.5*arrayLength));
	m_values = new double[arrayLength];

	for (int i = 0; i <= arrayLength; i++) {
		m_values[i] = m_blackScholes1FactorPDE->initialCondition(minSpotValue - i*m_dx);
	}
}
