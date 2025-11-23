#include <iostream>
using namespace std;
int main()
{
	int a = 10, b = 10, c = 1010;
	do
	{
		a = c / 100;
		b = c % 100;
		if (!(a == 0 || b == 0))
		{
			if ((c % (a * b)) == 0)
			{
				cout << "a = " << a << " " << "b = " << b << endl;
			}
		}
		c = c + 1;
	} while (c <= 9999);
	return 0;
}
