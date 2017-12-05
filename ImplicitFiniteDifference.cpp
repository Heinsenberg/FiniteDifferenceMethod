#include "stdafx.h"
#include "ImplicitFiniteDifference.h"

double ImplicitFiniteDifference::a(double _t, int _j) {	
	double result = -_t*(m_model->diffusionCoeff(1, _j) - 0.5*m_model->driftCoeff(0,_j));
	return result;
}

double ImplicitFiniteDifference::b(double _t, int _j) {
	double result = 1.0 + 2*_t*m_model->diffusionCoeff(1,_j) + _t*m_model->driftCoeff(0, 1);
	return result;
}

double ImplicitFiniteDifference::c(double _t, int _j) {
	double result = -_t*(m_model->diffusionCoeff(1, _j) + 0.5*m_model->driftCoeff(0, _j));
	return result;
}

