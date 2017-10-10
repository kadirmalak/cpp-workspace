#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct Cell
{
	double value;
};

template <typename T>
class Matrix
{
public:
	Matrix(size_t rows, size_t cols) : arr { rows } // arr = vector< vector<T> >(rows); anlamýnda
	{
		for (int i = 0; i < rows; i++)
		{
			arr[i].resize(cols);
		}
	}

	auto numrows() const
	{
		return arr.size();
	}

	auto numcols() const
	{
		return numrows() ? arr[0].size() : 0;
	}

	// const Matrix<T> & tipi olunca, [] operatoründe bu çaðýrýlýyor
	const auto & operator[] (int row) const
	{
		return arr[row];
	}

	// Matrix<T> & tipi olunca, [] operatoründe bu çaðýrýlýyor
	auto & operator[] (int row)
	{
		return arr[row];
	}

	static auto copy(const Matrix<T> & from, Matrix<T> & to)
	{
		for (int i = 0; i < from.numrows(); i++)
		{
			to[i] = from[i];
			//from[i] = vector<T>(); does not compile!
		}
	}

private:
	vector< vector<T> > arr;
};

int main()
{
	Matrix<int> m1(5, 3);
	Matrix<Cell> m2(7, 8);

	m1[0][0] = 1;
	m1[1][1] = 2;

	Matrix<int> m3(5, 3);

	cout << "m1[0][0]: " << m1[0][0] << endl;
	cout << "m1[1][1]: " << m1[1][1] << endl;

	cout << "m3[0][0]: " << m3[0][0] << endl;
	cout << "m3[1][1]: " << m3[1][1] << endl;

	Matrix<int>::copy(m1, m3);

	cout << "m3[0][0]: " << m3[0][0] << endl;
	cout << "m3[1][1]: " << m3[1][1] << endl;

	return 0;
}

