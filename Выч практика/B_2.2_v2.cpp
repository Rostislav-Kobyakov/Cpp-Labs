#include <iostream>
#include <iomanip>
using namespace std;
void ArrayFilling(int n, double* A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter number" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << ":";
			cin >> A[i * n + j];
		}

	}
}
void ArrayPrinting(int n, double* A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << A[i * n + j];
		cout << endl;
	}
}

void function(int n, double* A, double* B, double* C)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				C[i * n + j] += A[i * n + k] * B[k * n + j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				C[i * n + j] += B[i * n + k] * A[k * n + j];
		}
	}
}
int main()
{
	int n;
	cout << "Enter n: " << endl;
	cin >> n;
	cout << endl;
	double* A = new double [n];
	ArrayFilling(n, A);
	cout << endl << "Matrix A: " << endl;
	ArrayPrinting(n, A);
	double* B = new double [n];
	ArrayFilling(n, B);
	cout << endl << "Matrix B: " << endl;
	ArrayPrinting(n, B);
	cout << endl << "Enter zero" << endl << endl;
	double* C = new double [n];
	ArrayFilling(n, C);
	function(n, A, B, C);
	cout << endl << "Matrix C: " << endl;
	ArrayPrinting(n, C);
	delete []A;
	delete []B;
	delete []C;

}
