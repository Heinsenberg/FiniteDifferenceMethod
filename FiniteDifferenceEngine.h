#ifndef __FINITE_DIFFERENCE_ENGINE_H
#define __FINITE_DIFFERENCE_ENGINE_H

#include <vector>
#include "stdafx.h"
#include "ImplicitFiniteDifference.h"
#include "BoundaryAndInitialConditions.h"

using namespace std;

class FiniteDifferenceEngine {
public:
	FiniteDifferenceEngine();
	~FiniteDifferenceEngine();

	void calculate(int _numberOfSpotLevels, int _numberOfTimeSteps);

	ImplicitFiniteDifference* getImplicitFiniteDifference() const { return m_implicitFiniteDifference; }
	void setImplicitFiniteDifference(ImplicitFiniteDifference* _implicitFiniteDifference) { m_implicitFiniteDifference = _implicitFiniteDifference; }

	BoundaryAndInitialConditions* getBoundaryAndInitialConditions() const { return m_boundaryAndInitialConditions; }
	void setBoundaryAndInitialConditions(BoundaryAndInitialConditions* _boundaryAndInitialConditions) { m_boundaryAndInitialConditions = _boundaryAndInitialConditions; }

	vector<double> getFinalResult() { return m_finalOutput; };

private:

	ImplicitFiniteDifference* m_implicitFiniteDifference;
	BoundaryAndInitialConditions* m_boundaryAndInitialConditions;

	void calculateTimeStepSize();
	void calculateSpaceStepize(int _arrayLength);
	void createInitialCondition(int _arrayLength);
	void createModelMatrix(int _arrayLength);

	double m_dx;
	double m_dt;
	int m_numberOfTimeSteps;
	
	vector<double> m_initialCondition;
	vector<double> m_subdiagonal;
	vector<double> m_superdiagonal;
	vector<double> m_diagonal;
	vector<double> m_finalOutput;

};

#endif

