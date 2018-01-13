#ifndef __MARKET_ENVIRONMENT_H
#define __MARKET_ENVIRONMENT_H

#include "CurrencyPair.h"
#include <vector>

class MarketEnvironment
{
public:
	MarketEnvironment();
	MarketEnvironment(CurrencyPair* _ccyPair, double _fxSpot, vector<double> _discountFactorAsset, vector<double> _discountFactorNumeraire, double _volatility);
	~MarketEnvironment();
	
	CurrencyPair* getCurrencyPair() const { return m_currencyPair; }
	double getFXSpot() const { return m_fxSpot; }
	vector<double> getDiscountFactorAsset() const { return m_discountFactorAsset; }
	vector<double> getDiscountFactorNumeraire() const { return m_discountFactorNumeraire; }
	double getVolatility() const { return m_volatility; }
	double getAnnualFactor() const { return m_annualFactor; }

	double getAnnualFactor() { return m_annualFactor; }
	void setAnnualFactor(double _annualFactor) { m_annualFactor = _annualFactor ; }

private:
	CurrencyPair* m_currencyPair;
	vector<double> m_discountFactorAsset;
	vector<double> m_discountFactorNumeraire;
	double m_fxSpot;
	double m_volatility;
	double m_annualFactor;
};

#endif

