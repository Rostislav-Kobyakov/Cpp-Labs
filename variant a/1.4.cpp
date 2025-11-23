#include <iostream>
using namespace std;

int main()
{
	double x, y;
	cout << "Enter x " << endl;
	cin >> x;
	cout << "Enter y " << endl;
	cin >> y;
	if (x * x + y * y <= 4 && x * x + y * y >= 1 && x >= 0 && y <= 0)
		cout << "Coordinate fit" << endl;
	else
		cout << "Coordinate not fit" << endl;
	return 0;
}

