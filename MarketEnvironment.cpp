#include "stdafx.h"
#include "MarketEnvironment.h"

MarketEnvironment::MarketEnvironment(double _fxSpot, double _discountFactorAsset, 
									 double _discountFactorNumeraire, double _volatility)
{
	m_fxSpot = _fxSpot; 
	m_discountFactorAsset = _discountFactorAsset; 
	m_discountFactorNumeraire = _discountFactorNumeraire;
	m_volatility = _volatility;
}

