#include "MarketEnvironment.h"

MarketEnvironment::MarketEnvironment() {
	
}

MarketEnvironment::MarketEnvironment(CurrencyPair* _currencyPair, double _fxSpot, vector<double> _discountFactorAsset, 
									 vector<double> _discountFactorNumeraire, double _volatility){
	m_currencyPair = _currencyPair;
	m_fxSpot = _fxSpot; 
	m_discountFactorAsset = _discountFactorAsset; 
	m_discountFactorNumeraire = _discountFactorNumeraire;
	m_volatility = _volatility;
}


MarketEnvironment::~MarketEnvironment() {

}
