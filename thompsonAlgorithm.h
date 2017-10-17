#pragma once
#ifndef __THOMPSON_ALGORITHM_H
#define __THOMPSON_ALGORITHM_H

class ThompsonAlgorithm {
public:


	void ThompsonAlgorithmLU(double *b, double *a, double *c, double *l, double *u, double *d);
	void ThompsonAlgorithmSolve(double *l, double *u, double *d, double *x, double *q);
	
	int getDimension();
	void setDimension(int N) ;


private:
	int m_N;
};

#endif
