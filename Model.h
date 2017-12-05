#ifndef  __MODEL_H
#define __MODEL_H

#include "MarketEnvironment.h"

class Model
{
public:
	Model();
	~Model();

	// Diffusion coefficient
	virtual double diffusionCoeff(double t, double x) const;

	// Convection coefficient
	virtual double driftCoeff(double t, double x) const;

	void setMarketEnvironment(MarketEnvironment* _marketEnvironment) { m_marketEnvironment = _marketEnvironment; };

protected:
	MarketEnvironment* m_marketEnvironment;
};

class OneFactorBlackScholes : public Model {

public:
	// Diffusion coefficient
	 double diffusionCoeff(double t, double x) const override;

	// Convection coefficient
	double driftCoeff(double t, double x) const override;
};

#endif
