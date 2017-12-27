#ifndef __PAY_OFF_H
#define __PAY_OFF_H

class PayOff {
public:
	PayOff(); 
	virtual ~PayOff() {}; 

// Overloaded () operator, turns the PayOff into an abstract functor
	virtual double operator() (const double& S) const = 0;
};

class PayOffVanilla : public PayOff {

public:
	PayOffVanilla(const double& strike_, const int& _callPutFlag);
	virtual ~PayOffVanilla() {};

	// Virtual function is now over-ridden (not pure-virtual anymore)
	virtual double operator() (const double& S) const;
	double getStrike() const { return m_strike; };
	int getCallPutFlag() const { return m_callPutFlag; };

private:
	double m_strike;
	int m_callPutFlag;

};

#endif

