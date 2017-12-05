#ifndef __IMPLICIT_FINITE_DIFFERENCE_H
#define __IMPLICIT_FINITE_DIFFERENCE_H

#include <vector>
#include "stdafx.h"
#include "BoundaryAndInitialConditions.h"
#include "Model.h"

class ImplicitFiniteDifference {

public:

	double a(double _t, int _j);
	double b(double _t, int _j);
	double c(double _t, int _j);

	Model* getModel() const { return m_model; }
	void setModel(Model* _model) { m_model = _model; }

private:

	Model* m_model;
	
};


#endif