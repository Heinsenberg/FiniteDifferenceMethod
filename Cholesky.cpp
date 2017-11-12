#include "stdafx.h"
#include "Cholesky.h"

// we solve the problem Ax=b => x=(A^-1)*b;
//

Cholesky::Cholesky(vector<double> initialMatrix)
{
	size_t size = int(sqrt(initialMatrix.size()));
	m_matrixDimension = size;

	m_LU.resize(size*size);

	double sum = 0.0;
	
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < (i + 1); j++) {
			
			sum = 0.0;
			for (int k = 0; k < j; k++) {
				sum += m_LU[i * size + k] * m_LU[j * size + k];
			}
				m_LU[i * size + j] = (i == j) ?
					sqrt(initialMatrix[i * size + i] - sum) :
					(1.0 / m_LU[j * size + j] * (initialMatrix[i * size + j] - sum));
			
		}
	}

}

void Cholesky::solve(vector<double> x, vector<double> b)
{
	
	vector<double> y;
	y.resize(m_matrixDimension);
	
	for (int i = 0; i<m_matrixDimension; ++i) {
		
		double sum = 0.0;
		
		for (int k = 0; k < i; ++k) {
			sum += m_LU[i*m_matrixDimension + k] * y[k];
		}
		
		y[i] = (b[i] - sum) / m_LU[i*m_matrixDimension + i];
	}
	
	for (int i = m_matrixDimension - 1; i >= 0; --i) {
		
		double sum = 0.0;
		
		for (int k = i + 1; k < m_matrixDimension; ++k) {
			sum += m_LU[k*m_matrixDimension + i] * x[k];
		}
		
		x[i] = (y[i] - sum) / m_LU[i*m_matrixDimension + i];
	}

}
