#include <iostream>
#include <iomanip>
using namespace std;

int down(int &counter, int*& pa, int n, int k)
{// вниз
	for (int i = k; i > 0; i--)
	{
		pa += n;
		*pa = ++counter;
	}
		return counter;
}


int up(int &counter, int*& pa, int n, int k)
{// вверх
	for (int i = k; i > 0; i--)
	{
		pa -= n;
		*pa = ++counter;
	}
		return counter;
}
int left(int &counter, int*& pa, int n, int k)
{//влево
	for (int i = k; i > 0; i--)
	{
		pa -= 1;
		*pa = ++counter;
	}
		return counter;
}
int right(int &counter, int*& pa, int n, int k)
{//вправо
	for (int i = k; i > 0; i--)
	{
		pa += 1;
		*pa = ++counter;
	}
		return counter;
}
void output(int* a, int n)
{//вывод

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << *(a++);
		}
		cout << endl;
	}

}

int main()
{
	int const n = 5;
	int a[n*n], counter = 0;
	int* pa;
	pa = a - 1;
	//do
	//{
	//	for (int i = n; i > 0; i--)
	//	{
	//		*pa = ++counter;
	//		pa += n;
	//	}
	//	pa -= n;
	//	for (int i = n - 1; i > 0; i--)
	//	{
	//		pa -= 1;
	//		*pa = ++counter;
	//	}
	//	for (int i = n - 1; i > 0; i--)
	//	{
	//		pa -= n;
	//		*pa = ++counter;
	//	}
	//	for (int i = n - 2; i > 0; i--)
	//	{
	//		pa += 1;
	//		*pa = ++counter;
	//	}
	//	//
	//	for (int i = n - 2; i > 0; i--)
	//	{
	//		pa += n;
	//		*pa = ++counter;
	//	}
	//	for (int i = n - 3; i > 0; i--)
	//	{
	//		pa -= 1;
	//		*pa = ++counter;
	//	}
	//	for (int i = n - 3; i > 0; i--)
	//	{
	//		pa -= n;
	//		*pa = ++counter;
	//	}
	//	for (int i = n - 4; i > 0; i--)
	//	{
	//		pa += 1;
	//		*pa = ++counter;
	//	}
	//	for (int i = n - 4; i > 0; i--)
	//	{
	//		pa += n;
	//		*pa = ++counter;
	//	}
	//} while (*pa != n * n);
	
	//	for (int i = n; i > 0; i--)//первые шаги вниз
	//			{
	//				*pa = ++counter;
	//				pa += n;
	//			}
	//			pa -= n;
	//	for (int k = 1; k < n,(counter != n * n);) // заполнение матрицы
	//	{
	//		for (int i = n - k; i > 0; i--) // влево
	//		{
	//			pa -= 1;
	//			*pa = ++counter;
	//		}
	//		for (int i = n - k; i > 0; i--) // вверх
	//		{
	//			pa -= n;
	//			*pa = ++counter;
	//		}
	//		++k;
	//		for (int i = n - k; i > 0; i--) // вправо
	//		{
	//			pa += 1;
	//			*pa = ++counter;
	//		}
	//		for (int i = n - k; i > 0; i--)// вниз
	//		{
	//			pa += n;
	//			*pa = ++counter;
	//		}
	//		++k;
	//	}

	//for (int i = 0, k = 0; i < n*n; i++, k++)
	//{
	//	cout << setw(4) << a[i];
	//	if ((k + 1) % n == 0)
	//	{
	//		cout << endl;
	//	}
	//}
	int k = n;
	down(counter, pa, n, k);
	--k;
	for (; k > 0, (counter != n * n);)
	{
		left(counter, pa, n, k);
		up(counter, pa, n, k);
		--k;
		right(counter, pa, n, k);
		down(counter, pa, n, k);
		--k;
	}
	output(a, n);
	return 0;
}
