#pragma once
#include <vector>

using namespace std;

class Cholesky
{
public:
	Cholesky(vector<double> initialMatrix);
	void solve(vector<double> x, vector<double> b);

	vector<double> getLU() const { return m_LU; }
	int getMatrixDimension() const { return m_matrixDimension; }

private:
	vector<double> m_LU;
	int m_matrixDimension;

};

