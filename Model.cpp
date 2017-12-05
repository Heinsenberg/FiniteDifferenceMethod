#include "stdafx.h"
#include "Model.h"
#include <math.h>

Model::Model() {
}

Model::~Model() {
}

double Model::diffusionCoeff(double t, double x) const
{
	return 0.0;
}

double Model::driftCoeff(double t, double x) const
{
	return 0.0;
}

double OneFactorBlackScholes::diffusionCoeff(double t, double x) const {
	double vol = m_marketEnvironment->getVolatility();
	return 0.5*vol*vol*x*x; 
}

double OneFactorBlackScholes::driftCoeff(double t, double x) const {
	double DFAsset = m_marketEnvironment->getDiscountFactorAsset()[0];
	double DFNumeraire = m_marketEnvironment->getDiscountFactorNumeraire()[0];

	double drift = log(DFAsset) - log(DFNumeraire);
	return drift*x;
}
