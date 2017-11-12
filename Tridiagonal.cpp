#include "stdafx.h"
#include "Tridiagonal.h"

Tridiagonal::Tridiagonal()
{
}

void Tridiagonal::LUDecomposition(vector<double> _subdiagonal, vector<double> _diagonal, vector<double> _superdiagonal)
{
	m_subdiagonal = _subdiagonal;
	m_diagonal = _diagonal;
	m_superdiagonal = _superdiagonal;

	size_t size = m_diagonal.size();

	for (int i = 0; i < (size - 1); i++) {
		m_subdiagonal[i] /= m_diagonal[i];
		m_diagonal[i + 1] -= m_subdiagonal[i] * m_superdiagonal[i];
	}
	
}

void Tridiagonal::solve(vector<double> _b )
{
	int i;
	size_t size = m_diagonal.size();
	m_x.resize(size);

	//         Solve the linear equation Ly = b for y, where L is a lower
	//         triangular matrix.

	m_x[0] = _b[0];
	
	for (i = 1; i <= size-1; i++) {
		m_x[i] = _b[i] - m_subdiagonal[i - 1] * m_x[i - 1];
	}

	m_x[size - 1] /= m_diagonal[size - 1];

	for (i = size - 2; i >= 0; i--) {
		m_x[i] -= m_superdiagonal[i] * m_x[i+1];
		m_x[i] /= m_diagonal[i];
	}
	
}


Tridiagonal::~Tridiagonal()
{
}
