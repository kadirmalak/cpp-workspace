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
	Matrix(size_t rows, size_t cols) : arr{ rows }
	{
		for (int i = 0; i < rows; i++) {
			arr[i].resize(cols);
		}
	}

	const vector<T> & operator[] (size_t row) const {
		return arr[row];
	}

	vector<T> & operator[] (size_t row) {
		return arr[row];
	}

	static void copy(const Matrix<T> & from, Matrix<T> & to) {
		for (int i = 0; i < from.numrows(); i++) {
			to[i] = from[i];
		}
	}

	void print(ostream & out) const
	{
		for (size_t i = 0; i < numrows(); i++) {
			out << "[ ";
			for (size_t j = 0; j < numcols(); j++) {
				out << arr[i][j] << ((j == numcols() - 1) ? "" : " ");
			}
			out << " ]";
			out << endl;
		}
	}

	size_t numrows() const {
		return arr.size();
	}

	size_t numcols() const {
		return numrows() ? arr[0].size() : 0;
	}

private:
	vector< vector<T> > arr;
};

template <typename T>
ostream & operator << (ostream & out, const Matrix<T> & mat) {
	mat.print(out);
	return out;
}

int main()
{
	Matrix<int> m1(5, 3);
	Matrix<int> m2(5, 3);

	Matrix<Cell> m3(3, 8);

	m1[0][0] = 1;

	Matrix<int>::copy(m1, m2);

	cout << "m1[0][0]: " << m1[0][0] << endl;
	cout << "m2[0][0]: " << m2[0][0] << endl;

	cout << m2 << endl;

	return 0;
}
