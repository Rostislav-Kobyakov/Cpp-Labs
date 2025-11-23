#include <iostream>
using namespace std;
int main()
{
	int a, b, a1, b1, i;
	cout << "enter a" << endl;
	cin >> a;
	cout << "enter b" << endl;
	cin >> b;
	if (a > 0 && b > 0)
	{
		if (b < a)
		{
			b1 = b;
			a1 = a;
			a = b1;
			b = a1;
		}
		if (a < b)
		{
			for (i = a; i >= 1; i--)
			{
				if ((a % i == 0) && (b % i == 0))
				{
					cout << "nod is " << i << endl;
					break;
				}
			}
		}

	}
	else cout << "a and b is bad" << endl;
	return 0;
}