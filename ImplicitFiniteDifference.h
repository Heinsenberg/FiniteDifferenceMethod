#pragma once

using namespace std;

#include "stdafx.h"
#include <vector>
#include "BoundaryAndInitialConditions.h"
#include "BlackScholes1FactorPDE.h"

#ifndef __IMPLICIT_FINITE_DIFFERENCE_H
#define __IMPLICIT_FINITE_DIFFERENCE_H

class ImplicitFiniteDifference{

public:

	void calculate(int _numberOfSpotLevels,int _numberOfTimeSteps);
	
	BlackScholes1FactorPDE* getModel() const { return m_blackScholes1FactorPDE; }
	void setModel(BlackScholes1FactorPDE* _blackScholes1FactorPDE) { m_blackScholes1FactorPDE = _blackScholes1FactorPDE; }

	BoundaryAndInitialConditions* getBoundaryAndInitialConditions() const { return m_boundaryAndInitalConditions; }
	void setBoundaryAndInitialConditions(BoundaryAndInitialConditions* _boundaryAndInitalConditions) { m_boundaryAndInitalConditions = _boundaryAndInitalConditions; }

	vector<double> getInitialCondition() const { return m_initialCondition; }
	vector<double> getSubdiagonal() const { return m_subdiagonal; }
	vector<double> getSuperdiagonal() const { return m_superdiagonal; }
	vector<double> getDiagonal() const { return m_diagonal; }
	vector<double> getFinalOutput() const { return m_finalOutput; }

private:

	BlackScholes1FactorPDE* m_blackScholes1FactorPDE;
	BoundaryAndInitialConditions* m_boundaryAndInitalConditions;

	void calculateTimeStepSize();
	void calculateSpaceStepize(int _arrayLength);
	void createInitialCondition(int _arrayLength);
	void createModelMatrix(int _arrayLength);
	
	double m_dx;
	double m_dt;
	int m_numberOfTimeSteps;
	
	double a(int _j);
	double b(int _j);
	double c(int _j);

	vector<double> m_initialCondition;
	vector<double> m_subdiagonal;
	vector<double> m_superdiagonal;
	vector<double> m_diagonal;
	vector<double> m_finalOutput;

};


#endif