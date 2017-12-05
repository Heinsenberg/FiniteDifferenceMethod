#include "stdafx.h"
#include "FiniteDifferenceEngine.h"
#include "Tridiagonal.h"


FiniteDifferenceEngine::FiniteDifferenceEngine() {
}


FiniteDifferenceEngine::~FiniteDifferenceEngine() {
}


void FiniteDifferenceEngine::calculate(int _numberOfSpotLevels, int _numberOfTimeSteps) {

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

	for (int i = 1; i <= m_numberOfTimeSteps; i++) {
		b[0] -= m_boundaryAndInitialConditions->boundaryRight(i*m_dt, m_dx)*m_implicitFiniteDifference->a(m_dt,1);
		b[b.size() - 1] -= m_boundaryAndInitialConditions->boundaryLeft(i*m_dt, m_dx)*m_implicitFiniteDifference->c(m_dt,b.size() - 1);

		TridiagonalMatrix->solve(b);
		b = TridiagonalMatrix->getX();

	}

	m_finalOutput = b;
}

void FiniteDifferenceEngine::calculateTimeStepSize() {
	double expiryInDays = m_boundaryAndInitialConditions->getEuropeanOption()->getExpiryInDays();
	m_dt = expiryInDays / m_numberOfTimeSteps;

}

void FiniteDifferenceEngine::calculateSpaceStepize(int arrayLength) {
	double spot = m_boundaryAndInitialConditions->getMarketEnvironment()->getFXSpot();
	m_dx = spot / arrayLength;
}

void FiniteDifferenceEngine::createInitialCondition(int arrayLength) {

	size_t size = arrayLength;
	double m_dx = m_boundaryAndInitialConditions->getMarketEnvironment()->getFXSpot() / int(0.5*arrayLength);

	m_initialCondition.resize(size - 2);

	for (int i = 0; i < size - 2; i++) {
		m_initialCondition[i] = m_boundaryAndInitialConditions->initialCondition((i + 1)*m_dx);
	}
}

void FiniteDifferenceEngine::createModelMatrix(int arrayLength) {
	size_t size = arrayLength;

	m_subdiagonal.resize(size - 3); m_superdiagonal.resize(size - 3);
	m_diagonal.resize(size - 2);

	for (int i = 0; i < size - 3; i++) {
		m_subdiagonal[i] = m_implicitFiniteDifference->a(m_dt,i + 2);
		m_diagonal[i] = m_implicitFiniteDifference->b(m_dt,i + 1);
		m_superdiagonal[i] = m_implicitFiniteDifference->c(m_dt,i + 1);
	}

	m_diagonal[size - 3] = m_implicitFiniteDifference->b(m_dt,size - 2);
}

