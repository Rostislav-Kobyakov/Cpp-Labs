#include <iostream>
using namespace std;
int main()
{
	double a, b, c, t1, t2, D, x1, x2;
	cout << "ax^4 + bx^2 + c = 0" << endl;
	cout << "enter a" << endl;
	cin >> a;
	cout << "enter b" << endl;
	cin >> b;
	cout << "enter c" << endl;
	cin >> c;
	D = b * b - 4 * a * c;
	if (D >= 0)
	{
		t1 = (-b + sqrt(D)) / (2 * a);
		t2 = (-b - sqrt(D)) / (2 * a);
		if (!(t1 >= 0 && t2 >= 0))
		{
			cout << "no solution" << endl;
		}
		else
		{
			if (t1 >= 0)
			{
				x1 = sqrt(t1);
				cout << "x1 = " << x1 << endl
					<< "x2 = -" << x1 << endl;
			}
			if (t2 >= 0)
			{
				x2 = sqrt(t2);
				cout << "x3 = " << x2 << endl
					<< "x4 = -" << x2 << endl;
			}
		}
	}	
	else cout << "no solution" << endl;

}
