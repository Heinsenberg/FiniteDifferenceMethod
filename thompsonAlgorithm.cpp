#include "stdafx.h"
#include "thompsonAlgorithm.h"

//https://www.quantstart.com/articles/Tridiagonal-Matrix-Solver-via-Thomas-Algorithm

	void ThompsonAlgorithm::ThompsonAlgorithmLU(double *b, double *a, double *c, double *l, double *u, double *d){
	
		int i = 0;
		//LU decomposition
		
		d[0] = a[0]; u[0] = c[0];

		for (i = 0; i<m_N - 2; i++) {
			l[i] = b[i] / d[i];
			d[i + 1] = a[i + 1] - l[i] * u[i];
			u[i + 1] = c[i + 1];
		}

		l[m_N - 2] = b[m_N - 2] / d[m_N - 2];
		d[m_N - 1] = a[m_N - 1] - l[m_N - 2] * u[m_N - 2];
		
	}
	
	void ThompsonAlgorithm::ThompsonAlgorithmSolve(double *l, double *u, double *d, double *x, double *q){
		
		int i = 0;
		double *y = new double[m_N];

		y[0] = q[0];

		for (i = 1; i<m_N; i++)
			y[i] = q[i] - l[i - 1] * y[i - 1];
		// Backward Substitution [U][x] = [y] 
		x[m_N - 1] = y[m_N - 1] / d[m_N - 1];

		for (i = m_N - 2; i >= 0; i--)
			x[i] = (y[i] - u[i] * x[i + 1]) / d[i];
		delete[] y;
		return;
		
	}

	int ThompsonAlgorithm::getDimension(){
		return m_N;
	}

	void ThompsonAlgorithm::setDimension(int N) {
		m_N = N;
	}
