#ifndef __FINITE_DIFFERENCE_ENGINE_H
#define __FINITE_DIFFERENCE_ENGINE_H

#include <vector>
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

	ErrorHandler* getError() { return m_error; };

private:

	ImplicitFiniteDifference* m_implicitFiniteDifference;
	BoundaryAndInitialConditions* m_boundaryAndInitialConditions;

	void calculateTimeStepSize();
	void calculateSpaceStepize();
	void createInitialCondition();
	void createModelMatrix();

	double m_dx;
	double m_dt;
	int m_numberOfSpotSteps;
	int m_numberOfTimeSteps;
	
	vector<double> m_initialCondition;
	vector<double> m_subdiagonal;
	vector<double> m_superdiagonal;
	vector<double> m_diagonal;
	vector<double> m_finalOutput;

	ErrorHandler* m_error;

};

#endif

