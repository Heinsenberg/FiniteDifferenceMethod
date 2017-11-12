#include "stdafx.h"
#include "ImplicitFiniteDifference.h"
#include "Tridiagonal.h"

void ImplicitFiniteDifference::calculate(int _numberOfSpotLevels, int _numberOfTimeSteps) {

	int arrayLength = _numberOfSpotLevels;
	m_numberOfTimeSteps = _numberOfTimeSteps;

	calculateTimeStepSize();
	calculateSpaceStepize(arrayLength);
	createInitialCondition(arrayLength);
	createModelMatrix(arrayLength);

	// b = m_initialCondition
	// A = LU decomposition
	// x = the thing we need to figure out

	// Create an LU matrix. From a tridiagonal matrix
	Tridiagonal* TridiagonalMatrix = new Tridiagonal();
	TridiagonalMatrix->LUDecomposition(m_subdiagonal, m_diagonal, m_superdiagonal);
	
	vector<double> b = m_initialCondition;
	
	for (int i = 1; i <= m_numberOfTimeSteps; i++){
		
		b[0] -= m_boundaryAndInitalConditions->boundaryRight(i*m_dt, m_dx)*a(1);

		TridiagonalMatrix->solve(b);
		b = TridiagonalMatrix->getX();

		b[b.size()-1] -= m_boundaryAndInitalConditions->boundaryLeft(i*m_dt, m_dx)*c(b.size()-1);
		
	}
	
	m_finalOutput = b; 
}

void ImplicitFiniteDifference::calculateTimeStepSize()
{
	double expiryInDays = m_boundaryAndInitalConditions->getEuropeanOption()->getExpiryInDays();
	m_dt = expiryInDays/m_numberOfTimeSteps;

}

void ImplicitFiniteDifference::calculateSpaceStepize(int arrayLength){
	double spot = m_blackScholes1FactorPDE->getMarketEnvironment()->getFXSpot();
	m_dx = spot/arrayLength;
}

void ImplicitFiniteDifference::createInitialCondition(int arrayLength)
{
	
	size_t size = arrayLength;
	double m_dx = m_blackScholes1FactorPDE->getMarketEnvironment()->getFXSpot() / int(0.5*arrayLength);
	
	m_initialCondition.resize(size-2);
	
	for (int i = 0; i < size-2; i++) {
		m_initialCondition[i] = m_boundaryAndInitalConditions->initialCondition((i+1)*m_dx);
	}

}

void ImplicitFiniteDifference::createModelMatrix(int arrayLength)
{
	size_t size = arrayLength;
	
	m_subdiagonal.resize(size-3); m_superdiagonal.resize(size - 3);
	m_diagonal.resize(size-2); 

	for (int i = 0; i < size-3; i++) {
		m_subdiagonal[i] = a(i + 2);
		m_diagonal[i] = b(i + 1);
		m_superdiagonal[i] = c(i + 1); 
	}

		m_diagonal[size - 3] = b(size - 2);
}

double ImplicitFiniteDifference::a(int _j)
{	
	double result = -m_dt*(m_blackScholes1FactorPDE->diffCoeff(1, _j) - 0.5*m_blackScholes1FactorPDE->driftCoeff(0,_j));
	return result;
}

double ImplicitFiniteDifference::b(int _j)
{
	double result = 1.0 + 2*m_dt*m_blackScholes1FactorPDE->diffCoeff(1,_j) + m_dt*m_blackScholes1FactorPDE->driftCoeff(0, 1);
	return result;
}

double ImplicitFiniteDifference::c(int _j)
{
	double result = -m_dt*(m_blackScholes1FactorPDE->diffCoeff(1, _j) + 0.5*m_blackScholes1FactorPDE->driftCoeff(0, _j));
	return result;
}

