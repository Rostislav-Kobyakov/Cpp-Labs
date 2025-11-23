#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
void input(int &n, int *a)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

bool elementFinder(int n, int *a, int &max, bool flag)
{
	for(int i = n - 1; i >= 0; i--)
	{
		for (int max_n = a[i]; (max_n % n == 0 && max_n != 0) || max_n == 1 ; max_n /= n)
		{
			if (max_n == 1)
			{
				max = a[i];
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	return flag;
}

int &output(int n, int *a, int& max, bool flag)
{
	if (flag)
		return max;
	else
		return a[n - 1];
}


int main()

{
	int n, max = 0, index = 0;
	cout << "enter n " << endl << endl;
	cin >> n;
	int *a = new int[n];
	input(n, a);
	sort(a, a + n);
	cout << "proverOchka" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	bool flag = false;
	elementFinder(n, a, max, flag);
	int& k = n;
	k = output(n, a, max, flag);
	k = 0;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}

	delete[]a;
}
/*
1. Входная функция для n + инициализация и вывод массива
2. сортировка массива
3. проверяем по порядку на деление на n до 1 + флаг
4. выводная функция
*/

//int &function()
//{
//	int n, max = 0, index = 0;
//	cin >> n;
//	int* a = new int[n];
//	qsort(a, n, sizeof(int), comp);
//	bool flag = false;
//	elementFinder(n, a, max, flag);
//	if (flag)
//		return max;
//	else
//		return a[n - 1] = 0;
//}