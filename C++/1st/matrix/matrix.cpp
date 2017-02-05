#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string.h>

using namespace std;

class Matrix
{
public:
	int rows;
	int columns;
	double * data;

	Matrix()
	{
		this->rows = 0;
		this->columns = 0;
		this->data = NULL;
	}

	Matrix(int rows, int columns)
	{
		this->rows = rows;
		this->columns = columns;
		this->data = new double[rows * columns];
	}

	Matrix(const Matrix& matrix) : Matrix(matrix.rows, matrix.columns)
	{
		memcpy(this->data, matrix.data, sizeof(double) * rows * columns);	
	}

	friend ostream& operator<<(ostream& out, const Matrix& matrix)
	{
		for (int i = 0; i < matrix.rows; i++)
		{
			double * rowPointer = matrix.data + i * matrix.columns;
			for (int j = 0; j < matrix.columns; j++)
			{
				out << *(rowPointer + j) << ' ';
			}
			out << endl;
		}
		return out;
	}

	~Matrix()
	{
		delete[] this->data;
	}
};
