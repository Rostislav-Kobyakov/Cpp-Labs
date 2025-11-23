#include <iostream>
#include <iomanip>
using namespace std;
void ArrayFilling(int n, double** A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter number" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << ":";
			cin >> A[i][j];
		}

	}
}
double **ArrayInitial(int n)
{
	double **A = new double* [n];
	for (int i = 0; i < n; i++)
		 A[i] = new double[n];
	return A;
	
}
void ArrayPrinting(int n, double** A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << A[i][j];
		cout << endl;
	}
}

void ArrayDeleting(int n, double** A)
{
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
	}
	delete[]A;
}

void function(int n, double **A, double **B, double **C) // C = A*B + B*A
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; ++k)
				C[i][j] += A[i][k] * B[k][j];
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; ++k)
				C[i][j] += B[i][k] * A[k][j];
		}

	}
}

int main()
{
	int n;
	cout << "Enter n: " << endl;
	cin >> n;
	cout << endl;
	double** A;
	A = ArrayInitial(n);
	ArrayFilling(n, A);
	cout << endl << "Matrix A: " << endl;
	ArrayPrinting(n, A);
	double** B;
	B = ArrayInitial(n);
	ArrayFilling(n, B);
	cout << endl << "Matrix B: " << endl;
	ArrayPrinting(n, B);
	cout << endl << "Enter zero" << endl << endl;
	double** C;
	C = ArrayInitial(n);
	ArrayFilling(n, C);
	function(n, A, B, C);
	cout << endl << "Matrix C: " << endl;
	ArrayPrinting(n, C);
	ArrayDeleting(n, A);
	ArrayDeleting(n, B);
	ArrayDeleting(n, C);
}
