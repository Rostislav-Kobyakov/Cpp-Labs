#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main()
{
	const int n = 80, i = n, j = n;
	int  A[i][j] = { 0 }, B[i][j] = { 0 }, max = 0;
	for (int k = 0; k < i; k++)
	{
		for (int l = 0; l < j; l++)
		{
			A[k][l] = rand() % 100;
		}
	}
	cout << "Matrix A: " << endl;
	for (int k = 0; k < i; k++)
	{
		for (int l = 0; l < j; l++)
		{
			cout << setw(3) << A[k][l];
		}
		cout << endl;
	}
	cout << endl;
	for (int k = 0; k < i / 2; k++) // проходка по матрице
	{
		for (int l = 0; l < j / 2; l++)
		{
			for (int k1 = k; k1 <= i - 1 - k; k1++) // алгоритм нахождения максимума
			{
				for (int l1 = l; l1 <= j - 1 - l; l1++)
				{
					if (max < A[k1][l1])
						max = A[k1][l1];
				}
			}
			B[k][l] = max; // заполнение
			B[i - 1 - k][l] = max;
			B[i - 1 - k][j - 1 - l] = max;
			B[k][j - 1 - l] = max;
			max = 0;
		}
	}
	cout << "Matrix B: " << endl;
	for (int k = 0; k < i; k++)
	{
		for (int l = 0; l < j; l++)
		{
			cout << setw(3) << B[k][l];
		}
		cout << endl;
	}
	return 0;
}
