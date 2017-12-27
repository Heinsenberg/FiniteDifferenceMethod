#include "stdafx.h"
#include "Model.h"
#include <math.h>

Model::Model() {
}

Model::~Model() {
}

double Model::diffusionSpotCoeff(double t, double x) const
{
	return 0.0;
}

double Model::diffusionVolatilityCoeff(double t, double x) const
{
	return 0.0;
}

double Model::driftSpotCoeff(double t, double x) const
{
	return 0.0;
}

double Model::driftVolatilityCoeff(double t, double x) const
{
	return 0.0;
}

double OneFactorBlackScholes::diffusionSpotCoeff(double _t, double _x) const {
	double vol = m_marketEnvironment->getVolatility();
	return 0.5*vol*vol*_x*_x; 
}

double OneFactorBlackScholes::driftSpotCoeff(double _t, double _x) const {
	int tau = (int)_t;
	double DFAsset = m_marketEnvironment->getDiscountFactorAsset()[tau];
	double DFNumeraire = m_marketEnvironment->getDiscountFactorNumeraire()[tau];

	double drift = log(DFAsset/ DFNumeraire);
	return drift*_x;
}
