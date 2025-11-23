#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
std::size_t gAllocCounter = 0;
std::size_t gDeallocCounter = 0;

void* operator new(std::size_t size) {
	++gAllocCounter;
	return std::malloc(size);
};

void operator delete(void* ptr) {
	std::free(ptr);
	++gDeallocCounter;
};

void LeakState() {
	std::cout << std::endl;
	if (gAllocCounter != gDeallocCounter)
	{
		std::cout << "!!! LEAKS FOUND !!!" << std::endl;
		std::cout << "=== ALLOCATIONS COUNT: " << gAllocCounter << " ===" << std::endl;
		std::cout << "=== DEALLOCATIONS COUNT: " << gDeallocCounter << " ===" << std::endl;
	}
	else {
		std::cout << "=== LEAKS NOT FOUND ===" << std::endl;
	}
};
void ArrayFilling(int n, vector<int>& A)
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
void ArrayPrinting(int n, vector<int>& A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << A[i * n + j];
		cout << endl;
	}
}

void function(int n, vector<int>& A, vector<int>& B, vector<int>& C)
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
	vector<int> A(n*n);
	ArrayFilling(n, A);
	cout << endl << "Matrix A: " << endl;
	ArrayPrinting(n, A);
	vector<int> B(n * n);
	ArrayFilling(n, B);
	cout << endl << "Matrix B: " << endl;
	ArrayPrinting(n, B);
	cout << endl << "Enter zero" << endl << endl;
	vector<int> C(n * n);
	ArrayFilling(n, C);
	function(n, A, B, C);
	cout << endl << "Matrix C: " << endl;
	ArrayPrinting(n, C);
}