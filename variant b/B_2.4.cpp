#include <iostream>
using namespace std;
int main()
{
	int n, kvadrat = 0, kvadrat_pr = 0;
	for (int i = 1; i <= 10; i++)
	{
		cout << "enter n" << endl;
		cin >> n;
		cout << endl;
		if (int(sqrt(n)) * sqrt(n) == n)
		{
			++kvadrat;
			if (kvadrat > kvadrat_pr)
				kvadrat_pr = kvadrat;
		}
		else
		{
			kvadrat = 0;
		}
	}
	cout << "max posled = " << kvadrat_pr << endl;

	return 0;
}
