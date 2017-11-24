#pragma once
#include "stdafx.h"
#include "CurrencyPair.h"

#ifndef __MARKET_ENVIRONMENT_H
#define __MARKET_ENVIRONMENT_H

class MarketEnvironment
{
public:
	MarketEnvironment();
	MarketEnvironment(CurrencyPair* _ccyPair, double _fxSpot, double _discountFactorAsset, double _discountFactorNumeraire, double _volatility);
	~MarketEnvironment();
	
	CurrencyPair* getCurrencyPair() const { return m_currencyPair; }
	double getFXSpot() const { return m_fxSpot; }
	double getDiscountFactorAsset() const { return m_discountFactorAsset; }
	double getDiscountFactorNumeraire() const { return m_discountFactorNumeraire; }
	double getVolatility() const { return m_volatility; }

private:
	CurrencyPair* m_currencyPair;
	double m_fxSpot;
	double m_discountFactorAsset;
	double m_discountFactorNumeraire;
	double m_volatility;
};

#endif

