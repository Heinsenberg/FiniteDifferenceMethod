#pragma once
#include <vector>

using namespace std;

class Tridiagonal
{
public:
	Tridiagonal();
	void LUDecomposition(vector<double> _subdiagonal, vector<double> _diagonal, vector<double> _superdiagonal);
	void solve(vector<double> _b);

	vector<double> getDiagonal() const { return m_diagonal; };
	vector<double> getSubdiagonal() const { return m_subdiagonal; };
	vector<double> getSuperdiagonal() const { return m_superdiagonal; };
	vector<double> getX() const { return m_x; };

	~Tridiagonal();

private:
	vector<double> m_diagonal;
	vector<double> m_subdiagonal;
	vector<double> m_superdiagonal;

	vector<double> m_x;

};

