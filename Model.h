#ifndef  __MODEL_H
#define __MODEL_H

#include "MarketEnvironment.h"

class Model
{
public:
	Model();
	~Model();

	// Diffusion coefficient
	virtual double diffusionSpotCoeff(double t, double x) const;

	// Diffusion coefficient
	virtual double diffusionVolatilityCoeff(double t, double x) const;

	// Convection coefficient
	virtual double driftSpotCoeff(double t, double x) const;

	// Convection coefficient
	virtual double driftVolatilityCoeff(double t, double x) const;


	void setMarketEnvironment(MarketEnvironment* _marketEnvironment) { m_marketEnvironment = _marketEnvironment; };

protected:
	MarketEnvironment* m_marketEnvironment;
};

class OneFactorBlackScholes : public Model {

public:
	// Diffusion coefficient
	 double diffusionSpotCoeff(double _t, double _x) const ;

	// Convection coefficient
	double driftSpotCoeff(double _t, double _x) const ;
};

#endif
